# Set Matrix Zeroes

**Difficulty:** Medium | **Category:** Matrix
**LeetCode:** https://leetcode.com/problems/set-matrix-zeroes/

## Problem Understanding
If any cell in the matrix is 0, set its entire row and column to 0 — in place, using
O(1) extra space.

## Approach
**Use the first row and first column as marker space** instead of allocating new
arrays. Before overwriting them, separately remember whether the first row/column
*themselves* originally contained a zero (since we're about to reuse them as markers).

## Algorithm
1. Record whether the first row or first column originally contains a zero.
2. Scan the rest of the matrix (`r,c` starting at 1): if `matrix[r][c] == 0`, mark
   `matrix[r][0] = 0` and `matrix[0][c] = 0`.
3. Scan again (starting at 1,1): zero out any cell whose row-marker or column-marker
   is 0.
4. Finally, zero the first row/column themselves if they originally had a zero.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Doing the first-row/first-column check *before* the marking phase is critical —
  otherwise we couldn't tell whether a marker was "real" data or one we just wrote.
- The final two `if` blocks apply the deferred zeroing to row 0 / column 0 themselves,
  using the flags captured in step 1.

## Dry Run
`matrix = [[1,1,1],[1,0,1],[1,1,1]]`

- firstRowHasZero=False, firstColHasZero=False.
- Mark phase: `matrix[1][1]==0` → set `matrix[1][0]=0`, `matrix[0][1]=0`.
- Zero phase: cell (1,0)=0 or (0,1)=0 zeroes out row1/col1 cells accordingly.
- Neither flag set, so row0/col0 untouched beyond the markers already placed.

Result: `[[1,0,1],[0,0,0],[1,0,1]]`.

## Complexity
- Time: O(rows * cols)
- Space: O(1) extra.

## Edge Cases
- A zero already in the first row or column → correctly handled by the separate flags.
- All-zero matrix → every cell stays zero.
- Matrix with no zeroes at all → unchanged.
