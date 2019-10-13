let arrayArgAsString = Node.Process.argv[2];
let desiredSum = int_of_string(Node.Process.argv[3]);
let actualArray = LabsUtils.getArrayFromString(arrayArgAsString);

// returns subsets of specific length for an array
let rec getSubsets = (listOfSubsets, arr, start, len, arrayLength) => {
  if (start + len > arrayLength) {
    listOfSubsets;
  } else {
    let subset = Array.sub(arr, start, len);
    let newList = List.append(listOfSubsets, [subset]);
    getSubsets(newList, arr, start + 1, len, arrayLength);
  }
}

// returns all subsets (length 1 to n) from an array
let rec getAllSubsets = (listOfSubsets, arr, n) => {
  let arrayLength = Array.length(arr);
  if (n == 1) {
    let updatedList = List.append(listOfSubsets, [arr]);
    getAllSubsets(updatedList, arr, n + 1);
  } else if (n <= arrayLength) {
    let subSetLength = arrayLength + 1 - n;
    let subSets = getSubsets([], arr, 0, subSetLength, arrayLength);
    let updatedList = List.append(listOfSubsets, subSets);
    getAllSubsets(updatedList, arr, n + 1);
  } else {
    listOfSubsets;
  }
}

let sumOfArray = arrayToSum => arrayToSum |> Array.fold_left((sum, element) => sum + element, 0);
let isArraySumDesired = arrayToCheck => sumOfArray(arrayToCheck) == desiredSum;

let allSubsets = getAllSubsets([] ,actualArray, 1);
let filteredSubsets = allSubsets |> List.filter(isArraySumDesired)
Js.log(Array.of_list(filteredSubsets))
