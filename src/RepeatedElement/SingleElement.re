let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("SingleElement");

let make = (_, ~elementName, ~elementNumber) => {
  ...component,
  render: (_) =>
    <div>
      (
        str(
          "this element named: "
          ++ elementName
          ++ " and is element number: "
          ++ string_of_int(elementNumber),
        )
      )
    </div>,
};
