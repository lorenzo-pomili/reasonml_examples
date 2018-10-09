let component = ReasonReact.statelessComponent("ContainerElement");

let make = children => {
  ...component,
  render: _self =>
    <div>
      <div> {ReasonReact.string("content is down here")} </div>
      <div> {ReasonReact.array(children)} </div>
      <div> {ReasonReact.string("content is up here")} </div>
    </div>,
};
