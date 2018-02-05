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
