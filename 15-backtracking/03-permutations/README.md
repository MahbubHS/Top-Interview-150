# Permutations

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/permutations/

## Problem Understanding
Return every ordering of an array of distinct integers.

## Approach
Fill positions one by one. At each position try every element that is not already used, recurse for the next position, then undo the choice (backtrack). A `used` array tracks which indices are in the current path.

## Algorithm
1. If the path length equals `len(nums)`, save a copy.
2. For each unused index: mark used, append, recurse, pop, unmark.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[1,2,3]` → 6 permutations: `[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]`.

## Complexity
- Time: O(n × n!)
- Space: O(n) recursion + output

## Edge Cases
- Single element → one permutation.
- Elements are distinct, so no duplicate filtering is needed.
