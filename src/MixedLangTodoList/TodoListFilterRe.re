[@bs.module]
external todoListFilter : ReasonReact.reactClass = "./TodoListFilter";

let make = (~onUpdate, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=todoListFilter,
    ~props={"onUpdate": onUpdate},
    children
  );
