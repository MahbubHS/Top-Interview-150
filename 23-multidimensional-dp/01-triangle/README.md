# Triangle

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/triangle/

## Problem Understanding
Find the minimum path sum from the top of a triangle to the bottom, moving to one of the two adjacent numbers on the next row at each step.

## Approach
Work **bottom-up**: the minimum path sum from any cell equals that cell's value plus the smaller of the two possible next-row choices directly below it. Starting the DP array as the last row and folding upward one row at a time reduces the whole triangle to a single answer at `dp[0]`.

## Algorithm
1. Initialize `dp` as a copy of the last row.
2. For each row from second-to-last up to the top: `dp[col] = triangle[row][col] + min(dp[col], dp[col+1])` (reusing the same array, since each row only depends on the row below).
3. Return `dp[0]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[2],[3,4],[6,5,7],[4,1,8,3]]`: folding from the bottom gives minimum path `2→3→5→1 = 11`.

## Complexity
- Time: O(n²) where n is the number of rows
- Space: O(n) — one row-sized array reused in place

## Edge Cases
- Single-row triangle → the answer is that one value.
- Negative numbers → handled naturally since only `min` comparisons matter, no sign assumptions.
