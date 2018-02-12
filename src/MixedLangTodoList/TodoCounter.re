let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoCounter");

let make = (_, ~elementList) => {
  ...component,
  render: (_) =>
    <div>
      (
        str(
          "Number of items filtered: "
          ++ string_of_int(TodoElement.get_length(elementList))
        )
      )
    </div>
};
