# N-Queens II

**Difficulty:** Hard | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/n-queens-ii/

## Problem Understanding
Count the ways to place `n` queens on an `n x n` board so that no two attack each other (same row, column or diagonal).

## Approach
Place one queen per row. A queen at `(r, c)` is safe if its column and both diagonals are free. Diagonals are identified by `r - c` (one direction) and `r + c` (the other). Backtrack row by row, marking and unmarking the column and diagonals.

## Algorithm
1. `bt(r)`: if `r == n`, this is one full valid placement → return 1.
2. For each column `c`, skip if column, `r-c` diagonal or `r+c` diagonal is taken.
3. Mark them, add `bt(r+1)`, unmark.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n = 4` → `2` solutions; `n = 1` → `1`.

## Complexity
- Time: O(n!) with pruning
- Space: O(n)

## Edge Cases
- `n = 2` and `n = 3` have 0 solutions.
- Array versions offset `r - c` by `n - 1` to keep indexes non-negative.
