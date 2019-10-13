# TUM Functional Programming labs

Labs were done using [ReasonML](https://reasonml.github.io/)

## Prep

To install and build the project:

```bash
npm i
npm run build
```

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

- `getSubsets`: returns subsets of specific length for an array
  e.g.:
  `length = 2`
  `array = [1, 2, 3]`
  result: `[[1, 2], [2, 3]]`
- `getAllSubsets`: returns all subsets (length 1 to n) from an array
  e.g.:
  `length = 2`
  `array = [1, 2, 3]`
  result: `[[1, 2, 3], [1, 2], [2, 3], [1], [2], [3]]`

Using helpers functions `sumOfArray` and `isArraySumDesired` for each subset, check if it satisfies the condition. Then print the result to the console.

The code can be seen in [`src/Subsets.re`](https://github.com/strdr4605/tum-fp-labs/blob/master/src/Subsets.re).

### Lab2 Examples

![image](https://user-images.githubusercontent.com/16056918/66722364-3b696e80-ee15-11e9-9d39-7bb5f6fc8011.png)
