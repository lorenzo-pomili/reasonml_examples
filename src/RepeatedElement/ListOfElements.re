let str = ReasonReact.stringToElement;

let mockList: list(Element.element) = [
  {id: 0, name: "First Element", number: 1},
  {id: 1, name: "Second Element", number: 2},
  {id: 2, name: "Third Element", number: 3}
];

let component = ReasonReact.statelessComponent("ListOfElements");

let make = (_) => {
  ...component,
  render: (_) =>
    <div>
      (
        ReasonReact.arrayToElement(
          Array.of_list(
            List.map(
              (element: Element.element) =>
                <SingleElement
                  key=("singleElementKey_" ++ string_of_int(element.id))
                  elementName=element.name
                  elementNumber=element.number
                />,
              mockList
            )
          )
        )
      )
    </div>
};
