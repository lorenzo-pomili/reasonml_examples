let get = () : Js.Promise.t(list(Element.element)) =>
  Js.Promise.(
    Fetch.fetch(ServicesConst.server_url ++ "/getData")
    |> then_(Fetch.Response.json)
    |> then_(json => resolve(Element.Decode.to_element_list(json)))
  );

let getStorage = () : Js.Promise.t(list(Element.element)) =>
  Js.Promise.(
    Fetch.fetch(ServicesConst.server_url ++ "/getDataStorage")
    |> then_(Fetch.Response.json)
    |> then_(json => resolve(Element.Decode.to_element_list(json)))
  );

let set = elementsList =>
  Js.Promise.(
    Fetch.fetchWithInit(
      ServicesConst.server_url ++ "/setData",
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=
          Fetch.BodyInit.make(
            Json.stringify(Element.Encode.to_element_list(elementsList))
          ),
        ()
      )
    )
    |> resolve
  );
