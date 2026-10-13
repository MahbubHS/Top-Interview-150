# Number of 1 Bits

**Difficulty:** Easy | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/number-of-1-bits/

## Problem Understanding
Count the number of set bits (1s) in an integer's binary representation (Hamming weight).

## Approach
**Brian Kernighan's trick.** `n & (n-1)` clears the lowest set bit of `n` in one operation (subtracting 1 flips all trailing zeros to ones and the lowest 1 to a zero; ANDing with the original then removes exactly that bit). Repeating this exactly as many times as there are set bits reaches 0.

## Algorithm
1. `count = 0`.
2. While `n != 0`: `n &= n - 1` (clear the lowest set bit), increment `count`.
3. Return `count`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n = 11` = `1011` in binary: step1 clears to `1010` (count1), step2 clears to `1000` (count2), step3 clears to `0000` (count3) → `3`.

## Complexity
- Time: O(k) where k is the number of set bits (at most 32)
- Space: O(1)

## Edge Cases
- `n = 0` → 0 set bits.
- All bits set (`0xFFFFFFFF`) → 32, handled correctly since the loop runs exactly 32 times in that case.
