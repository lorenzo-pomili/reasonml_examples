let str = ReasonReact.string;

type state = {
  data: list(Element.element),
  dataStorage: list(Element.element),
  currentInput: string,
};

let valueOfEvent = event => ReactDOMRe.domElementToObj(
                              ReactEventRe.Form.target(event),
                            )##value;

type action =
  | UpdateInput(string)
  | Add(string)
  | GetFromServer
  | UpdateFromServer(list(Element.element))
  | Save(list(Element.element));

let getNewId = data => List.length(data);

let getNewNumber = data => List.length(data) + 1;

let save = elements_list : unit => DataService.set(elements_list) |> ignore;

let getStoredData = send =>
  DataService.getStorage()
  |> Js.Promise.then_(result_promise =>
       Js.Promise.resolve(send(UpdateFromServer(result_promise)))
     )
  |> ignore;

let component = ReasonReact.reducerComponent("SetAndGetItemInService");

let make = _ => {
  ...component,
  initialState: () => {data: [], dataStorage: [], currentInput: ""},
  reducer: (action, state) =>
    switch (action) {
    | Add(text) =>
      ReasonReact.Update({
        ...state,
        currentInput: "",
        data:
          state.data
          @ [
            Element.makeElement(
              getNewId(state.data),
              text,
              getNewNumber(state.data),
            ),
          ],
      })
    | UpdateInput(text) => ReasonReact.Update({...state, currentInput: text})
    | Save(elements_list) =>
      save(elements_list);
      ReasonReact.NoUpdate;
    | GetFromServer =>
      ReasonReact.SideEffects((self => getStoredData(self.send)))
    | UpdateFromServer(elements_list) =>
      ReasonReact.Update({...state, dataStorage: elements_list})
    },
  render: self =>
    <div>
      <div>
        <div> (str("Add element")) </div>
        <input
          _type="text"
          value=self.state.currentInput
          onChange=(event => self.send(UpdateInput(valueOfEvent(event))))
        />
        <button
          disabled=(self.state.currentInput == "")
          onClick=(_event => self.send(Add(self.state.currentInput)))>
          (str("Add"))
        </button>
        <ListOfElements elementsList=self.state.data />
        <button
          disabled=(List.length(self.state.data) == 0)
          onClick=(_event => self.send(Save(self.state.data)))>
          (str("Save"))
        </button>
      </div>
      <div>
        <button onClick=(_event => self.send(GetFromServer))>
          (str("Get"))
        </button>
        <ListOfElements elementsList=self.state.dataStorage />
      </div>
    </div>,
};
