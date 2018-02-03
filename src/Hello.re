let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("Main");

let make = children => {
  ...component,
  render: self => <div> (str("Hello world!")) </div>
};
