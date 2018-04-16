open ReasonReact;

let str = stringToElement;

let component = statelessComponent("SecondPage");

let make = (_, ~phrase, ~num) => {
  ...component,
  render: (_) => {
    let gotoHome = event => {
      ReactEventRe.Mouse.preventDefault(event);
      ReasonReact.Router.push("/");
    };
    <div>
      <h1> (stringToElement("SecondPage")) </h1>
      <div>
        <span> (str("Phrase: ")) </span>
        <span> (str(phrase)) </span>
      </div>
      <div>
        <span> (str("Num: ")) </span>
        <span> (str(string_of_int(num))) </span>
      </div>
      <a href="#" onClick=gotoHome> (stringToElement("Home")) </a>
    </div>;
  },
};
