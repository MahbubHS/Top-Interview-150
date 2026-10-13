# Sqrt(x)

**Difficulty:** Easy | **Category:** Math
**LeetCode:** https://leetcode.com/problems/sqrtx/

## Problem Understanding
Compute the integer square root of a non-negative integer `x` (round down), without using a built-in power/sqrt function.

## Approach
Binary search the answer: the candidate values `1..x` have squares that increase monotonically, so search for the largest `mid` whose square is `<= x`. Searching up to `x/2` (rather than `x`) is a safe tighter bound for `x >= 2` since any integer root is at most half of `x`.

## Algorithm
1. `x < 2` → return `x` directly (0 or 1 are their own roots).
2. Binary search `lo=1, hi=x/2`: compute `mid*mid`; exact match returns `mid` immediately.
3. Too small → search higher (`lo = mid+1`); too big → search lower (`hi = mid-1`).
4. When the loop ends, `hi` holds the floor of the square root.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`x = 8`: candidates narrow down; `2*2=4<8` so lo rises, `3*3=9>8` so hi falls to 2 → loop ends with `hi=2` → `2` (since `sqrt(8)≈2.83`).

## Complexity
- Time: O(log x)
- Space: O(1)

## Edge Cases
- `x = 0` or `x = 1` → returned directly.
- Perfect squares (e.g. `x=16`) → the exact-match branch returns immediately.
