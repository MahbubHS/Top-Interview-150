# Unique Paths II

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/unique-paths-ii/

## Problem Understanding
Count paths from top-left to bottom-right of a grid (moving only right or down) that avoid obstacle cells.

## Approach
Rolling 1D DP over columns, same shape as a plain grid-path-count problem, with one extra rule: an obstacle cell has exactly 0 ways to be entered, regardless of what the DP would otherwise compute, since no path may pass through it.

## Algorithm
1. `dp[0] = 1` (assuming the start isn't itself blocked — if it is, this gets zeroed on the first iteration).
2. For each cell: if it's an obstacle, `dp[c] = 0`.
3. Otherwise (for `c > 0`) accumulate the ways from the left: `dp[c] += dp[c-1]` (the existing `dp[c]` already holds the "from above" count carried from the previous row).
4. Return `dp[last column]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[0,0,0],[0,1,0],[0,0,0]]`: the middle obstacle blocks the direct diagonal-ish routes, leaving exactly `2` valid paths around it.

## Complexity
- Time: O(rows × cols)
- Space: O(cols)

## Edge Cases
- Start or end cell is an obstacle → 0 paths.
- No obstacles at all → reduces to the standard unique-paths binomial-coefficient count.
