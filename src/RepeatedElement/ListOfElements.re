let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("ListOfElements");

let make = (_, ~elementsList) => {
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
              elementsList
            )
          )
        )
      )
    </div>
};
