# Valid Sudoku

**Difficulty:** Medium | **Category:** Matrix
**LeetCode:** https://leetcode.com/problems/valid-sudoku/

## Problem Understanding
Check whether a partially-filled 9x9 Sudoku board is valid: no repeated digit in any
row, column, or 3x3 sub-box. Empty cells are `'.'` and are ignored. (We only validate
the current state — not whether the puzzle is solvable.)

## Approach
Track seen digits for each of the 9 rows, 9 columns, and 9 boxes using sets, scanning
the board once. Each cell maps to exactly one row-set, one column-set, and one
box-set — the box index is computed from `(r/3)*3 + c/3`.

## Algorithm
1. Create 9 empty sets each for rows, columns, and boxes.
2. For each filled cell `(r, c)` with value `val`: compute box index `b`.
3. If `val` already appears in `rows[r]`, `cols[c]`, or `boxes[b]`, return False.
4. Otherwise add `val` to all three sets.
5. If the full scan completes, return True.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `(r // 3) * 3 + c // 3` maps any `(r,c)` to a box index 0-8 by first finding which
  of the 3 box-rows and box-columns it belongs to, then flattening to a single index.
- Checking membership in all three sets before inserting is what enforces all three
  Sudoku constraints simultaneously in one pass.

## Dry Run
Board with two `'8'`s in the same row → when the second `'8'` is scanned,
`val in rows[r]` is already True (from the first `'8'`) → immediately return `False`.

## Complexity
- Time: O(1) — the board is always 9x9, so this is really O(81) constant work.
- Space: O(1) — 27 sets of bounded size (at most 9 digits each).

## Edge Cases
- Completely empty board (`.` everywhere) → trivially valid.
- Board that violates only a box constraint but no row/column constraint → still
  correctly caught via `boxes[b]`.
