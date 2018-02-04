let get = () : Js.Promise.t(list(Element.element)) =>
  Js.Promise.(
    Fetch.fetch(ServicesConst.server_url ++ "/getData")
    |> then_(Fetch.Response.json)
    |> then_(json => resolve(Element.Decode.to_element_list(json)))
  );
