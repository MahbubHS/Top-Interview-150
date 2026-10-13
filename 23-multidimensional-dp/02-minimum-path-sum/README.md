# Minimum Path Sum

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/minimum-path-sum/

## Problem Understanding
Find the minimum sum path from the top-left to the bottom-right of a grid, moving only right or down.

## Approach
A rolling 1D DP over columns: `dp[c]` after processing row `r` holds the minimum path sum to reach `(r, c)`. Arriving at `(r,c)` comes either from above (`dp[c]` before this row's update) or from the left (`dp[c-1]`, already updated for this row), so taking the smaller of the two and adding the current cell builds the answer incrementally.

## Algorithm
1. `dp` initialized to "infinity" except conceptually position (0,-1); `dp[0]` accumulates straight down the first column as each row is entered.
2. For each row, `dp[0] += grid[r][0]` (only one way to reach the first column — straight down).
3. For each other column, `dp[c] = grid[r][c] + min(dp[c], dp[c-1])`.
4. Return `dp[last column]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[1,3,1],[1,5,1],[4,2,1]]`: the optimal path `1→3→1→1→1` sums to `7`.

## Complexity
- Time: O(rows × cols)
- Space: O(cols) — one row-sized array

## Edge Cases
- Single row → forced to move only right, sum is just the row total.
- Single column → forced to move only down.
