let getArrayFromString = (arrayAsString, fn) => arrayAsString |> Js.String.split(",") |> Array.map(fn);
