# House Robber

**Difficulty:** Medium | **Category:** 1D DP
**LeetCode:** https://leetcode.com/problems/house-robber/

## Problem Understanding
Houses are in a row, each with some money. Adjacent houses cannot both be robbed. Maximize the total take.

## Approach
At each house, decide: skip it (carry forward the best total without it) or rob it (its value plus the best total from two houses back, since the immediate neighbor is now off-limits). Track just the previous two best totals rather than a full array.

## Algorithm
1. `prev2 = prev1 = 0` (best totals for "before the array" states).
2. For each house value: `cur = max(prev1, prev2 + num)` — skip vs. rob.
3. Shift the window; return `prev1` at the end.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[2,7,9,3,1]`: step by step best-so-far becomes 2, 7, 11, 11, 12 → `12` (rob houses 2,9,1... specifically 2+9+1=12).

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Empty array → 0.
- Single house → its value.
- Two houses → the larger of the two.
