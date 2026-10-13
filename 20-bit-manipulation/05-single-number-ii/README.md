# Single Number II

**Difficulty:** Medium | **Category:** Bit Manipulation
**LeetCode:** https://leetcode.com/problems/single-number-ii/

## Problem Understanding
Every element appears exactly three times except for one, which appears once. Find that element in O(n) time, O(1) space.

## Approach
**Two-variable bitwise state machine.** `ones` and `twos` together track, per bit position, a 2-bit counter (mod 3) of how many times that bit has appeared: `00 → 01 → 10 → 00` as a bit is seen 0, 1, 2, 3 times. After processing every number, a bit that appeared a multiple of 3 times is back to `00`; the bit belonging only to the singleton stays in `ones`.

## Algorithm
1. `ones = twos = 0`.
2. For each `num`: `ones = (ones ^ num) & ~twos` (add num to ones, but zero out positions already in twos).
3. `twos = (twos ^ num) & ~ones` (similarly, add num to twos while respecting the just-updated ones).
4. Return `ones`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[2,2,3,2]`: after processing all four numbers, bit positions belonging to the triplicated 2 cycle back to 0, leaving `ones = 3`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Works for negative numbers too since bitwise operations apply uniformly to two's-complement representation.
- Single-element array → that element.
