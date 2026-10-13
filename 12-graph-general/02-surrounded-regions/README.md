# Surrounded Regions

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/surrounded-regions/

## Problem Understanding
Flip every region of `'O'` cells that is completely surrounded by `'X'` (a region touching the board border is not captured).

## Approach
Think in reverse: instead of finding surrounded regions, find the `'O'` cells that are **safe** — those connected to a border `'O'`. Mark them `'T'` with a flood fill starting from the border. Everything still `'O'` afterward is surrounded, so flip it to `'X'`; then turn `'T'` back into `'O'`.

## Algorithm
1. Seed a stack with all border `'O'` cells, marking them `'T'`.
2. Flood fill: mark every `'O'` reachable from them as `'T'`.
3. Final sweep: `'O'` → `'X'`, `'T'` → `'O'`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Board with a lone interior `'O'` block and one `'O'` on the bottom border: the border one (and anything attached) becomes `'T'` then back to `'O'`; the interior block flips to `'X'`.

## Complexity
- Time: O(rows × cols)
- Space: O(rows × cols) worst case

## Edge Cases
- Boards with 2 or fewer rows/columns have no interior → nothing changes.
- An `'O'` region touching any edge cell is never flipped.
