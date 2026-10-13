# Construct Quad Tree

**Difficulty:** Medium | **Category:** Divide & Conquer
**LeetCode:** https://leetcode.com/problems/construct-quad-tree/

## Problem Understanding
Given an `n x n` binary grid (n a power of 2), build a quad tree: a leaf represents a region that is
entirely 0s or entirely 1s; otherwise a node splits into four equal quadrants, each built the same way.

## Approach
**Divide and conquer on the grid.** For a square region, first check if every cell is identical — if
so it's a leaf. Otherwise split into four quadrants of half the size and recurse on each, combining
them under one internal node.

## Algorithm
1. `build(r, c, size)`: check whether all cells in the `size × size` block starting at `(r, c)` equal
   the top-left cell.
2. If uniform, return a leaf `Node(value, True)`.
3. Otherwise, recursively build the four `size/2` quadrants and return an internal node
   `Node(True, False, tl, tr, bl, br)` (the internal node's `val` is conventionally `True` and ignored
   by checkers).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The uniformity check scans the whole block; this repeated scanning is what makes the straightforward
  version O(n² log n) rather than O(n²), but it keeps the logic simple and matches the problem's
  typical constraint sizes.
- Splitting always into four equal quadrants relies on the grid size being a power of 2 (guaranteed).

## Dry Run
`grid = [[0,1],[1,0]]`: not uniform → 4 quadrants of size 1, each trivially uniform → one internal node
with four leaves `0,1,1,0` (top-left, top-right, bottom-left, bottom-right).

## Complexity
- Time: O(n² log n) for the direct approach (each of O(log n) levels rescans the grid).
- Space: O(n²) in the worst case (checkerboard pattern) for the resulting tree.

## Edge Cases
- Entirely uniform grid → a single leaf node, no recursion into quadrants.
- `1x1` grid → always a single leaf.
- Checkerboard pattern → recursion goes all the way down to 1×1 leaves everywhere.
