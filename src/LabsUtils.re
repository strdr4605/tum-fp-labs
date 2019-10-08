let getArrayFromString = arrayAsString => arrayAsString |> Js.String.split(",") |> Array.map(int_of_string);
