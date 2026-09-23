# H-Index

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/h-index/

## Problem Understanding
Given citation counts per paper, find the largest `h` such that the researcher has at
least `h` papers with at least `h` citations each.

## Approach
Sort citations in descending order. Walk down the sorted list: as long as the citation
count at position `i` (0-indexed) is at least `i+1`, that many papers qualify. The
largest such `i+1` is the H-Index.

## Algorithm
1. Sort `citations` descending.
2. For each index `i`, if `citations[i] >= i+1`, update `h = i+1`.
3. Stop as soon as this condition fails (citations only decrease further).
4. Return `h`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.
(Java sorts ascending and iterates from the back since `Arrays.sort` has no built-in
descending primitive sort.)

## Line-by-Line Explanation
- After descending sort, `citations[i] >= i+1` means "the first i+1 papers each have
  at least i+1 citations" — exactly the H-Index definition.
- Once a position fails the check, every later (smaller) citation count fails too, so
  we can break early.

## Dry Run
`citations = [3,0,6,1,5]` → sorted desc: `[6,5,3,1,0]`

| i | citations[i] | i+1 | qualifies? | h |
|---|--------------|-----|------------|---|
| 0 | 6 | 1 | yes | 1 |
| 1 | 5 | 2 | yes | 2 |
| 2 | 3 | 3 | yes | 3 |
| 3 | 1 | 4 | no | 3 |

Result: `3`.

## Complexity
- Time: O(n log n) for the sort.
- Space: O(1) extra (O(log n) for sort internals).

## Edge Cases
- All zero citations → h = 0.
- All papers with huge citations → h capped at total paper count `n`.
