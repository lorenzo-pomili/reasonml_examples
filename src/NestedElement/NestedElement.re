let component = ReasonReact.statelessComponent("NestedElement");

let make = _ => {
  ...component,
  render: _self =>
    <div>
      <ContainerElement>
        {ReasonReact.string("Mono element")}
      </ContainerElement>
      <ContainerElement>
        {ReasonReact.string("First Nested Element")}
        <div key="0"> {ReasonReact.string("Second Nested Element")} </div>
      </ContainerElement>
    </div>,
};
