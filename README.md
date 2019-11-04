# TUM Functional Programming labs

Labs were done using [ReasonML](https://reasonml.github.io/)

## Table of contents
* [Preparation](#preparation)
* [Lab1](#lab1)
* [Lab2](#lab2)

## Preparation

To install and build the project:

```bash
npm i
npm run build
```

## Table of contents

- [Lab1](#lab1)
- [Lab2](#lab2)
- [Lab3](#lab3)

## Lab1

> Sort a list of integers

For this lab I implemented QuickSort. The code can be seen in [`src/QuickSort.re`](https://github.com/strdr4605/tum-fp-labs/blob/master/src/QuickSort.re). After the build you can run:

```bash
node lib/js/src/QuickSort.bs.js 1,3,9,0,6
```

Where the last argument are the numbers **separeted by `,`**

### Lab1 Examples

![image](https://user-images.githubusercontent.com/16056918/66345356-96541f00-e958-11e9-920e-b840982d845b.png)
![image](https://user-images.githubusercontent.com/16056918/66345412-b4218400-e958-11e9-8c83-ec2763cf72a2.png)

## Lab2

> Find all subsets of an array that sums to a desired sum.

To solve this problem I implemented following functions:

- `getSubsets`: _returns subsets of specific length for an array_  
  example:  
  length: `2`  
  array: `[1, 2, 3]`  
  result: `[[1, 2], [2, 3]]`  
- `getAllSubsets`: _returns all subsets (length 1 to n) from an array_  
  example:  
  array: `[1, 2, 3]`  
  result: `[[1, 2, 3], [1, 2], [2, 3], [1], [2], [3]]`

Using helpers functions `sumOfArray` and `isArraySumDesired` for each subset, check if it satisfies the condition. Then print the result to the console.

The code can be seen in [`src/Subsets.re`](https://github.com/strdr4605/tum-fp-labs/blob/master/src/Subsets.re). After the build you can run:

```bash
node lib/js/src/Subsets.bs.js 1,3,-16,5,7,8,2,2 12
```

### Lab2 Examples

![image](https://user-images.githubusercontent.com/16056918/66722711-dc5a2880-ee19-11e9-9fbf-086b55cc8d8d.png)
![image](https://user-images.githubusercontent.com/16056918/66722705-d2382a00-ee19-11e9-8dc9-e40cf4bb4a58.png)
![image](https://user-images.githubusercontent.com/16056918/66722699-c5b3d180-ee19-11e9-9afc-aa5c6a08a66c.png)



## Lab3

> Eliminate left recursion from a Formal grammar

### Lab3 Examples

![image](https://user-images.githubusercontent.com/16056918/68163591-8a617a00-ff63-11e9-9616-fd6421a4ab6f.png)
![image](https://user-images.githubusercontent.com/16056918/68163583-846b9900-ff63-11e9-8231-f11358902371.png)

