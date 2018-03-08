let str = ReasonReact.stringToElement;

type state = {
  filter: string,
  newElementDesc: string,
  elementList: list(TodoElement.todoElement),
  filteredElementList: list(TodoElement.todoElement),
};

let reactElementList = (elementList: list(TodoElement.todoElement)) =>
  List.map(
    element =>
      <TodoListElement
        key=(
          "singleTodoElementKey_"
          ++ string_of_int(TodoElement.get_id(element))
        )
        todoElement=element
      />,
    elementList,
  );

type action =
  | UpdateNewElementDesc(string)
  | AddElement
  | UpdateFilter(string);

let onFilterUpdate = (send, newFilter) => send(UpdateFilter(newFilter));

let component = ReasonReact.reducerComponent("TodoList");

let make = (_, ~elementList) => {
  ...component,
  initialState: () => {
    filter: "",
    newElementDesc: "",
    elementList,
    filteredElementList: elementList,
  },
  reducer: (action, state) =>
    switch (action) {
    | UpdateNewElementDesc(desc) =>
      ReasonReact.Update({...state, newElementDesc: desc})
    | AddElement =>
      ReasonReact.Update({
        ...state,
        newElementDesc: "",
        elementList:
          TodoElement.new_element_in_list(
            ~element_list=state.elementList,
            ~desc=state.newElementDesc,
          ),
        filteredElementList:
          TodoElement.filter_list(
            TodoElement.new_element_in_list(
              ~element_list=state.elementList,
              ~desc=state.newElementDesc,
            ),
            state.filter,
          ),
      })
    | UpdateFilter(filter) =>
      ReasonReact.Update({
        ...state,
        filter,
        filteredElementList:
          TodoElement.filter_list(state.elementList, filter),
      })
    },
  render: self =>
    <div>
      <TodoCounter elementList=self.state.filteredElementList />
      <TodoListFilterRe onUpdate=(onFilterUpdate(self.send)) />
      (
        ReasonReact.arrayToElement(
          Array.of_list(reactElementList(self.state.filteredElementList)),
        )
      )
      <div>
        <input
          placeholder="Insert new item"
          _type="text"
          value=self.state.newElementDesc
          onKeyPress=(
            e =>
              if (ReactEventRe.Keyboard.key(e) === "Enter") {
                self.send(AddElement);
              } else {
                ();
              }
          )
          onChange=(
            event =>
              self.send(
                UpdateNewElementDesc(
                  ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value,
                ),
              )
          )
        />
        <button onClick=((_) => self.send(AddElement))>
          (str("Add"))
        </button>
      </div>
    </div>,
};
