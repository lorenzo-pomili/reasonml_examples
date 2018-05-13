let str = ReasonReact.string;

let component = ReasonReact.statelessComponent("Hello");

let make = (_) => {
  ...component,
  render: (_) => <div> (str("Hello world!")) </div>,
};
