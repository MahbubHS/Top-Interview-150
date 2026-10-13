# Word Search

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/word-search/

## Problem Understanding
Check whether `word` can be spelled by a path of horizontally/vertically adjacent cells in the grid, using each cell at most once.

## Approach
Try every cell as a starting point and run a DFS that matches one letter per step. To avoid reusing a cell, temporarily overwrite it with `#` while exploring and **restore** it afterwards (backtracking). The search stops as soon as one path spells the whole word.

## Algorithm
1. For each cell, call `dfs(r, c, 0)`.
2. `i == len(word)` → success.
3. Out of bounds or letter mismatch → fail.
4. Mark the cell `#`, try the 4 neighbors with `i+1`, then restore the cell.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Board `[[A,B,C,E],[S,F,C,S],[A,D,E,E]]`, word `"ABCCED"` → `True`; `"ABCB"` → `False` (would reuse B).

## Complexity
- Time: O(rows × cols × 3^L)
- Space: O(L) recursion

## Edge Cases
- Word longer than the number of cells → `False`.
- Single-cell board equal to a one-letter word → `True`.
