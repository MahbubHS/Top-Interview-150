# Game of Life

**Difficulty:** Medium | **Category:** Matrix
**LeetCode:** https://leetcode.com/problems/game-of-life/

## Problem Understanding
Simulate one step of Conway's Game of Life on a board, in place, without using a
separate copy of the board. Each cell's next state depends on its 8 neighbors' *current*
(pre-update) states:
- Live cell with <2 or >3 live neighbors → dies.
- Live cell with 2-3 live neighbors → survives.
- Dead cell with exactly 3 live neighbors → becomes live.

## Approach
**In-place state encoding.** Since we must read every cell's *original* value while
computing everyone's next value, use intermediate codes that encode both the old and
new state in one integer: `2` = was live, now dead; `3` = was dead, now live. A
neighbor check like `board[nr][nc] in (1, 2)` (1=still live, 2=was-live-now-dead)
correctly still counts it as "live" for the purposes of the *original* board.

## Algorithm
1. For each cell, count live neighbors using `value == 1 or value == 2` as "was live."
2. Apply the transition rules, writing `2` (die) or `3` (become live) as needed instead
   of a plain 0/1, so untouched cells keep their original value for neighbors still to
   be processed.
3. Second pass: convert `2 → 0` and `3 → 1` to get the final board.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Checking neighbor value `1 or 2` (not just `1`) during the first pass is the key
  trick: it means "was live in the original board," regardless of whether we've
  already flagged that neighbor for death in code `2`.
- The second pass is a pure cleanup step, translating the two intermediate codes back
  to standard 0/1.

## Dry Run
`board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]` (classic "blinker" style pattern) —
applying the neighbor-count rules cell by cell transitions live cells with <2 or >3
neighbors to code `2`, dead cells with exactly 3 live neighbors to code `3`, then the
cleanup pass finalizes 0s and 1s. (See LeetCode's official example for the full
expected output grid.)

## Complexity
- Time: O(rows * cols) — 8 neighbor checks per cell, both constant-time.
- Space: O(1) extra (in-place encoding, no auxiliary board).

## Edge Cases
- 1x1 board → no neighbors exist, cell can only die if currently live (0 neighbors
  is always <2).
- All-dead board → stays all-dead (no cell has 3 live neighbors).
