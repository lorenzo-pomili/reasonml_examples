type element = {
  id: int,
  name: string,
  number: int,
};

module Decode = {
  open Json.Decode;
  let to_element = json : element => {
    id: json |> field("id", int),
    name: json |> field("name", string),
    number: json |> field("number", int),
  };
  let to_element_array = elements_json : array(element) =>
    elements_json |> array(to_element);
  let to_element_list = elements_json : list(element) =>
    Array.to_list(to_element_array(elements_json));
};

module Encode = {
  open Json.Encode;
  let to_element = (e: element) =>
    object_([
      ("id", int(e.id)),
      ("name", string(e.name)),
      ("number", int(e.number)),
    ]);
  let to_element_array = (elements: array(element)) =>
    elements |> array(to_element);
  let to_element_list = (elementsList: list(element)) =>
    to_element_array(Array.of_list(elementsList));
};

let makeElement = (i, n, num) => {id: i, name: n, number: num};
