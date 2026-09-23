# Zigzag Conversion

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/zigzag-conversion/

## Problem Understanding
Write the string in a zigzag pattern across `numRows` rows, then read it back row by
row, and return that resulting string.

## Approach
Simulate the zigzag directly: maintain a "current row" pointer that moves down (+1)
until it hits the last row, then moves up (-1) until it hits the first row, bouncing
back and forth. Append each character to its current row's buffer as we go.

## Algorithm
1. If `numRows == 1`, the zigzag is just the string itself — return early.
2. Maintain `cur` (current row) and `step` (+1 or -1).
3. For each character, append it to `rows[cur]`; flip `step` when `cur` hits row 0 or
   `numRows-1`; advance `cur` by `step`.
4. Concatenate all rows in order.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The bounce logic (`step` flips at the top and bottom rows) is exactly what produces
  the "V" zigzag shape when visualized.
- Building per-row buffers and concatenating at the end avoids any index-math formulas.

## Dry Run
`s = "PAYPALISHIRING"`, `numRows = 3`

Row assignment: P(0) A(1) Y(2) P(1) A(0) L(1) I(2) S(1) H(0) I(1) R(2) I(1) N(0) G(1)

Rows: `"PAHN"`, `"APLSIIG"`, `"YIR"` → concatenated: `"PAHNAPLSIIGYIR"`.

## Complexity
- Time: O(n)
- Space: O(n) for the row buffers.

## Edge Cases
- `numRows == 1` → output equals input unchanged.
- `numRows >= len(s)` → each character on essentially its own row, output equals input.
