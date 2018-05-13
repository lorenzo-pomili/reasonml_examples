module IndexWrapper = {
  open ReasonReact;
  type state = {currentContent: reactElement};
  type action =
    | ContentChanged(reactElement);
  let component = ReasonReact.reducerComponent("Index");
  let make = (_) => {
    ...component,
    initialState: () => {
      currentContent:
        MyRouter.getPageFromPath(
          ReasonReact.Router.dangerouslyGetInitialUrl().path,
        ),
    },
    render: self =>
      <div className="app">
        <h1> (string("Index wrapper")) </h1>
        <div> self.state.currentContent </div>
      </div>,
    reducer: (action, _) =>
      switch (action) {
      | ContentChanged(el) => ReasonReact.Update({currentContent: el})
      },
    subscriptions: self => [
      Sub(
        () => MyRouter.init(el => self.send(ContentChanged(el))),
        MyRouter.destroy,
      ),
    ],
  };
};

ReactDOMRe.renderToElementWithId(<IndexWrapper />, "root");
