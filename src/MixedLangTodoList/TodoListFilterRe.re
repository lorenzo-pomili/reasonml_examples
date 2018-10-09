[@bs.module "./TodoListFilter"]
external todoListFilter: ReasonReact.reactClass = "default";

let make = (~onUpdate, children) =>
  ReasonReact.wrapJsForReason(
    ~reactClass=todoListFilter,
    ~props={"onUpdate": onUpdate},
    children,
  );
