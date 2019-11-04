let arrayArgAsString = Node.Process.argv[2];
let actualArray = LabsUtils.getArrayFromString(arrayArgAsString, int_of_string);

let rec listFilter = (fn, l) => {
  switch l {
  | [] => []
  | [e] => fn(e) ? [e] : []
  | [head, ...tail] =>  fn(head) ? [head, ...listFilter(fn, tail)] : listFilter(fn, tail)
  };
}

let rec quickSort: list(int) => list(int) = listToSort => {
  switch listToSort {
  | [] => []
  | [e] => [e]
  | [head, ...tail] =>
    List.concat(
      [
        quickSort(listFilter(e => e < head, tail)),
        [head],
        quickSort(listFilter(e => e >= head, tail))
      ]
    )
  };
}

let sortedArray = actualArray |> Array.to_list |> quickSort |> Array.of_list

Js.log(sortedArray)
