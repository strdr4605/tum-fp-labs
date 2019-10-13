let arrayArgAsString = Node.Process.argv[2];
let desiredSum = int_of_string(Node.Process.argv[3]);
let actualArray = LabsUtils.getArrayFromString(arrayArgAsString);

let rec getSubsets = (listOfSubsets, arr, start, len, arrayLength) => {
  if (start + len > arrayLength) {
    listOfSubsets
  } else {
    let subset = Array.sub(arr, start, len);
    let newList = List.append(listOfSubsets, [subset]);
    getSubsets(newList, arr, start + 1, len, arrayLength);
  }
}

let rec getAllSubsets = (listOfSubsets, arr, n) => {
  let arrayLength = Array.length(arr);
  if (n == 1) {
    let updatedList = List.append(listOfSubsets, [arr])
    getAllSubsets(updatedList, arr, n + 1)
  } else if (n <= arrayLength) {
    let subSetLength = arrayLength + 1 - n;
    let subSets = getSubsets([], arr, 0, subSetLength, arrayLength);
    let updatedList = List.append(listOfSubsets, subSets)
    getAllSubsets(updatedList, arr, n + 1)
  } else {
    listOfSubsets
  }
}

let allSubsets = getAllSubsets([] ,actualArray, 1);
let arr = Array.of_list(allSubsets);
Js.log(arr);
