ReactDOMRe.renderToElementWithId(<Hello />, "root");

let mockList: list(Element.element) = [
  {id: 0, name: "First Element", number: 1},
  {id: 1, name: "Second Element", number: 2},
  {id: 2, name: "Third Element", number: 3}
];

ReactDOMRe.renderToElementWithId(
  <ListOfElements elementsList=mockList />,
  "listOfElements"
);

let render = data : unit =>
  ReactDOMRe.renderToElementWithId(
    <ListOfElements elementsList=data />,
    "listOfElementsFromServer"
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
  "setAndGetElementsInService"
);

let mockTodoElementList: list(TodoElement.todoElement) = [
  {id: 0, pos: 1, desc: "001", isDone: false},
  {id: 1, pos: 2, desc: "002", isDone: true},
  {id: 2, pos: 3, desc: "003", isDone: false}
];

ReactDOMRe.renderToElementWithId(
  <TodoList elementList=mockTodoElementList />,
  "mixedLangTodoList"
);
