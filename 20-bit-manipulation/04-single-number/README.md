# Single Number

**Difficulty:** Easy | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/single-number/

## Problem Understanding
Every element appears exactly twice except for one, which appears once. Find that element in O(n) time and O(1) space.

## Approach
XOR every number together. XOR is commutative/associative, `x ^ x = 0`, and `x ^ 0 = x` — so every pair of duplicates cancels to 0, leaving only the single unpaired number in the running XOR.

## Algorithm
1. `result = 0`.
2. XOR every number into `result`.
3. Return `result`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[4,1,2,1,2]`: `4^1^2^1^2 = 4^(1^1)^(2^2) = 4^0^0 = 4`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Single-element array → that element.
- The unpaired element can be anywhere in the array — XOR order does not matter.
