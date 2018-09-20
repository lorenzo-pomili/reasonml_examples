type t =
  | Main
  | SecondPage(string, int)
  | NotFound;

let getRoute = path =>
  switch (path) {
  | ["secondPage", phrase, num] => SecondPage(phrase, int_of_string(num))
  | ["secondPage"]
  | ["secondPage", _] => SecondPage("", 0)
  | [] => Main
  | _ => NotFound
  };

let getPageFromPath = path => {
  let route = getRoute(path);
  switch (route) {
  | Main => <Main />
  | SecondPage(phrase, num) =>
    <SecondPage phrase={Js.Global.decodeURI(phrase)} num />
  | NotFound => <Main />
  };
};

let init = pageChanged => {
  let watchId =
    ReasonReact.Router.watchUrl(url => {
      let page = getPageFromPath(url.path);
      pageChanged(page);
    });
  watchId;
};

let destroy = ReasonReact.Router.unwatchUrl;
