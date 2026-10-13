# Number of Islands

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/number-of-islands/

## Problem Understanding
Count the connected groups of land (`'1'`) in a grid, where connectivity is up/down/left/right.

## Approach
Scan every cell. Each time you meet unvisited land, that is a new island: increment the count, then flood-fill the whole island (turning its cells to `'0'`) so it isn't counted again. An explicit stack is used instead of recursion so very large islands can't overflow the call stack.

## Algorithm
1. Loop over all cells.
2. On `'1'`: `count += 1`, mark it `'0'`, push it on a stack.
3. Pop cells, marking and pushing any adjacent `'1'` neighbors, until the stack is empty.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Grid `[[1,1,0],[1,0,0],[0,0,1]]` → the top-left group is one island and the bottom-right cell another → `2`.

## Complexity
- Time: O(rows × cols)
- Space: O(rows × cols) worst case for the stack

## Edge Cases
- All water → 0.
- All land → 1.
- Diagonal neighbors do not connect.
