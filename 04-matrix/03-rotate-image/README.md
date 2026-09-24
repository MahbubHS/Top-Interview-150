# Rotate Image

**Difficulty:** Medium | **Category:** Matrix
**LeetCode:** https://leetcode.com/problems/rotate-image/

## Problem Understanding
Rotate an `n x n` matrix 90 degrees clockwise, in place, without allocating another
matrix.

## Approach
**Transpose, then reverse each row.** A 90° clockwise rotation is mathematically
equivalent to first transposing the matrix (flip across the main diagonal, swapping
`matrix[i][j]` with `matrix[j][i]`) and then reversing every row.

## Algorithm
1. Transpose: for each `i`, for each `j > i`, swap `matrix[i][j]` and `matrix[j][i]`
   (only the upper triangle needs visiting since each swap handles both sides).
2. Reverse every row in place.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The transpose loop uses `j starting at i+1` (not 0) specifically to avoid swapping
  each pair twice and to skip the diagonal (which maps to itself).
- Reversing rows after transposing completes the clockwise rotation — transposing
  alone only produces a mirror/flip, not a rotation.

## Dry Run
`matrix = [[1,2,3],[4,5,6],[7,8,9]]`

Transpose: `[[1,4,7],[2,5,8],[3,6,9]]`
Reverse each row: `[[7,4,1],[8,5,2],[9,6,3]]`

This matches rotating the original 90° clockwise.

## Complexity
- Time: O(n²)
- Space: O(1) — fully in place.

## Edge Cases
- 1x1 matrix → no-op, already "rotated."
- 2x2 matrix → transpose then reverse rows still produces the correct rotation.
