# Climbing Stairs

**Difficulty:** Easy | **Category:** 1D DP
**LeetCode:** https://leetcode.com/problems/climbing-stairs/

## Problem Understanding
You can climb 1 or 2 steps at a time. Count the distinct ways to reach step `n`.

## Approach
The number of ways to reach step `n` is the number of ways to reach `n-1` (then take a final 1-step) plus the ways to reach `n-2` (then take a final 2-step) — this is exactly the **Fibonacci recurrence**. Track only the last two values instead of a full DP array.

## Algorithm
1. Base cases: `n=1 → 1`, `n=2 → 2`.
2. `prev2, prev1 = 1, 2` (ways for steps 1 and 2).
3. For each step from 3 to n: `cur = prev1 + prev2`, shift the window forward.
4. Return `prev1`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n=5`: ways(3)=2+1=3, ways(4)=3+2=5, ways(5)=5+3=8 → `8`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- `n = 1` → 1 way.
- `n = 0` is outside constraints (n ≥ 1) but the formula would give 1 (empty climb).
