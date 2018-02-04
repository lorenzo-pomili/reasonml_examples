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
