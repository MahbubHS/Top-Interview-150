# Combinations

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/combinations/

## Problem Understanding
Return all combinations of `k` numbers chosen from `1..n` (order does not matter).

## Approach
Choose numbers in increasing order so each combination appears once: after picking `i`, only numbers greater than `i` may follow. Backtracking builds the path; the loop bound is pruned so we never start a number when too few remain to fill `k` slots.

## Algorithm
1. `bt(start)`: if the path has `k` numbers, save a copy.
2. For `i` from `start` up to `n - (k - len(path)) + 1`: append `i`, recurse with `i+1`, pop.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n=4, k=2` → `[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]`.

## Complexity
- Time: O(C(n,k) × k)
- Space: O(k) recursion + output

## Edge Cases
- `k = n` → a single combination of all numbers.
- `k = 1` → each number alone.
