# Maximal Square

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/maximal-square/

## Problem Understanding
Find the area of the largest square containing only '1's in a binary matrix.

## Approach
`dp[r][c]` = the side length of the largest all-1s square whose **bottom-right corner** is at `(r,c)`. A square of side `s` ending here requires the cell above, the cell to the left, AND the cell diagonally up-left to all support at least a side of `s-1` — so `dp[r][c] = 1 + min(up, left, diagonal)` when the current cell is '1' (and 0 otherwise, since no square can end on a '0').

## Algorithm
1. 1-indexed `dp` table (extra row/col of zeros) to avoid boundary checks.
2. For each '1' cell: `dp[r][c] = 1 + min(dp[r-1][c], dp[r][c-1], dp[r-1][c-1])`.
3. Track the largest `dp` value seen as `best` (the side length).
4. Return `best * best` (area).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[1,0,1,0,0],[1,0,1,1,1],[1,1,1,1,1],[1,0,0,1,0]]`: the largest square has side 2, found around rows 1-2, cols 2-3 → area `4`.

## Complexity
- Time: O(rows × cols)
- Space: O(rows × cols) (reducible to O(cols) with a rolling row)

## Edge Cases
- All zeros → `best` stays 0, area 0.
- All ones → `best` grows to `min(rows, cols)`, area that squared.
- Single row or column of all 1s → largest square is 1×1, area 1.
