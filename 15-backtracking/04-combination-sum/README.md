# Combination Sum

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/combination-sum/

## Problem Understanding
Given distinct positive integers and a target, return all unique combinations that sum to the target; each number may be used any number of times.

## Approach
Backtrack on the remaining sum. Recursing with the **same index** `i` allows reusing a number, while starting the loop at `start` (never going backward) prevents the same combination appearing in different orders.

## Algorithm
1. `bt(start, remaining)`: if `remaining == 0`, save the path.
2. For `i` from `start`: skip candidates larger than `remaining`; push, recurse with `(i, remaining - c)`, pop.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[2,3,6,7]`, target 7 → `[2,2,3]` and `[7]`.

## Complexity
- Time: O(N^(T/M)) where T is the target and M the smallest candidate
- Space: O(T/M) recursion depth

## Edge Cases
- Target smaller than every candidate → `[]`.
- A candidate equal to the target gives a one-element combination.
