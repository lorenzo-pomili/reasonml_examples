let str = ReasonReact.stringToElement;

let component = ReasonReact.statelessComponent("TodoListElement");

let make = (_, ~todoElement) => {
  ...component,
  render: (_) => <div> (str(TodoElement.get_desc(todoElement))) </div>,
};
