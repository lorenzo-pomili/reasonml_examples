type todoElement = {
  id: int;
  pos: int;
  desc: string;
  isDone: bool;
}

let get_desc e = e.desc

let get_id e = e.id

let get_length el = List.length el

let change_desc ~element ~new_desc = {element with desc = new_desc}

let toogle_done e = {e with isDone = (not e.isDone)}

let compare_by_pos e1 e2 = compare e1.pos e2.pos

let sort_by_pos el = List.sort compare_by_pos el

let compare_by_desc e1 e2 = compare e1.desc e2.desc

let sort_by_desc el = List.sort compare_by_desc el

let new_id_from_list el = List.length el

let new_position_from_list el = (List.length el) + 1

let new_element id pos desc isDone = {id; pos; desc; isDone}

let new_element_in_list ~element_list ~desc = element_list @ [new_element (new_id_from_list element_list) (new_position_from_list element_list) desc false]

let get_number_of_element el = (List.length el) + 1

let max_to_check desc str =
  let desc_l = String.length desc in
  let str_l = String.length str in
  desc_l - str_l

let desc_contain_str desc str =
  let max = max_to_check desc str in
  let rec aux current =
    match (current = max) with
    | true when (String.sub desc current (String.length str)) = str -> true
    | true -> false
    | false when (String.sub desc current (String.length str)) = str -> true
    | false -> aux (current +  1)
  in
  aux 0
;;

let filter_list el filter =
  match filter with
  | "" -> el
  | _ -> List.filter (fun e -> (desc_contain_str e.desc filter)) el
