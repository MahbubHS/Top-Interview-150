# Spiral Matrix

**Difficulty:** Medium | **Category:** Matrix
**LeetCode:** https://leetcode.com/problems/spiral-matrix/

## Problem Understanding
Return all elements of a matrix in spiral (clockwise, inward) order.

## Approach
**Shrinking boundary simulation.** Maintain four boundaries (`top`, `bottom`, `left`,
`right`). Traverse the top row left→right, the right column top→bottom, the bottom row
right→left, and the left column bottom→top, shrinking the corresponding boundary after
each pass. Guard the last two passes with boundary checks so a matrix that's down to a
single row or column doesn't get double-counted.

## Algorithm
1. While `top <= bottom` and `left <= right`:
2. Traverse top row → `top++`.
3. Traverse right column → `right--`.
4. If `top <= bottom` still: traverse bottom row (reversed) → `bottom--`.
5. If `left <= right` still: traverse left column (reversed) → `left++`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The guards before steps 4 and 5 are essential: without them, a matrix that's been
  reduced to a single row (after step 2) would have its "bottom row" re-traverse the
  same row already covered by the "top row" pass.

## Dry Run
`matrix = [[1,2,3],[4,5,6],[7,8,9]]`

- Top row: 1,2,3 → top=1
- Right col: 6,9 → right=1
- Bottom row (top≤bottom, 1≤2 true): 8,7 → bottom=1
- Left col (left≤right, 0≤1 true): 4 → left=1
- Loop again: top=1,bottom=1,left=1,right=1 → top row: 5 → top=2, loop ends.

Result: `[1,2,3,6,9,8,7,4,5]`.

## Complexity
- Time: O(m*n) — every cell visited exactly once.
- Space: O(1) extra (excluding the output array).

## Edge Cases
- Single row or single column matrix → handled correctly by the boundary guards.
- Single cell matrix → one pass, returns that one element.
