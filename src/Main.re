/* ReactDOMRe.renderToElementWithId(<Hello />, "root"); */
let mockList: list(Element.element) = [
  {id: 0, name: "First Element", number: 1},
  {id: 1, name: "Second Element", number: 2},
  {id: 2, name: "Third Element", number: 3},
];

/* ReactDOMRe.renderToElementWithId(
     <ListOfElements elementsList=mockList />,
     "listOfElements",
   ); */
/* let render = data : unit =>
     ReactDOMRe.renderToElementWithId(
       <ListOfElements elementsList=data />,
       "listOfElementsFromServer",
     );

   let renderServerElement = () =>
     DataService.get()
     |> Js.Promise.then_(result_promise => {
          render(result_promise);
          Js.Promise.resolve();
        });

   renderServerElement();

   ReactDOMRe.renderToElementWithId(
     <SetAndGetElementsInService />,
     "setAndGetElementsInService",
   ); */
let mockTodoElementList: list(TodoElement.todoElement) = [
  {id: 0, pos: 1, desc: "001", isDone: false},
  {id: 1, pos: 2, desc: "002", isDone: true},
  {id: 2, pos: 3, desc: "003", isDone: false},
];

/* ReactDOMRe.renderToElementWithId(
     <TodoList elementList=mockTodoElementList />,
     "mixedLangTodoList",
   ); */
let styleBorder1pxSolidRed =
  ReactDOMRe.Style.make(~border="1px solid #000000", ());

type action =
  | DataForListOfElementsFromServerRecived(list(Element.element));

type state = {
  dataForListOfElementsFromServer: option(list(Element.element)),
};

let goToSecondPage = (_) => ReasonReact.Router.push("/secondPage");

let goToSecondPageWithParams = (_) =>
  ReasonReact.Router.push("/secondPage/this is phrase test/42");

let str = ReasonReact.string;

let component = ReasonReact.reducerComponent("Main");

let make = (_) => {
  ...component,
  initialState: () => {dataForListOfElementsFromServer: None},
  reducer: (action, _) =>
    switch (action) {
    | DataForListOfElementsFromServerRecived(data) =>
      ReasonReact.Update({dataForListOfElementsFromServer: Some(data)})
    },
  render: self => {
    if (self.state.dataForListOfElementsFromServer == None) {
      DataService.get()
      |> Js.Promise.then_(result_promise => {
           self.send(DataForListOfElementsFromServerRecived(result_promise));
           Js.Promise.resolve();
         })
      |> ignore;
    } else {
      ();
    };
    <div>
      <h1> (str("Hello World")) </h1>
      <Hello />
      <br />
      <h1> (str("Repeated Element")) </h1>
      <ListOfElements elementsList=mockList />
      <br />
      <h1> (str("Elements getted from server")) </h1>
      (
        switch (self.state.dataForListOfElementsFromServer) {
        | Some(data) => <ListOfElements elementsList=data />
        | None => <div> (str("loading...")) </div>
        }
      )
      <br />
      <h1> (str("Set and get elements from server")) </h1>
      <div style=styleBorder1pxSolidRed> <SetAndGetElementsInService /> </div>
      <br />
      <h1> (str("Mixed language ToDoList")) </h1>
      <div style=styleBorder1pxSolidRed>
        <TodoList elementList=mockTodoElementList />
      </div>
      <div>
        <button onClick=goToSecondPage> (str("SecondPage")) </button>
        <button onClick=goToSecondPageWithParams>
          (str("SecondPage whit params"))
        </button>
      </div>
    </div>;
  },
};
