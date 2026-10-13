# Merge Intervals

**Difficulty:** Medium | **Category:** Intervals
**LeetCode:** https://leetcode.com/problems/merge-intervals/

## Problem Understanding
Given a collection of intervals, merge all overlapping ones and return the resulting
non-overlapping set.

## Approach
Sort intervals by start time. Then walk through in order, keeping a "current merged
interval" — if the next interval's start is `<=` the current merged interval's end,
they overlap (or touch), so extend the end; otherwise close off the current merged
interval and start a new one.

## Algorithm
1. Sort intervals by start value.
2. Initialize result with the first interval.
3. For each subsequent interval: if its start is `<=` the last result interval's end,
   merge by extending that end to `max(current end, new end)`. Otherwise append it as
   a new separate interval.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Sorting by start is what allows a single linear pass: once sorted, any interval that
  could possibly overlap the current merged one must immediately follow it.
- `max(last_end, end)` guards against a contained interval (e.g. `[1,10]` followed by
  `[2,3]`) incorrectly shrinking the merged end.

## Dry Run
`intervals = [[1,3],[2,6],[8,10],[15,18]]` → sorted (already sorted here)

- Start with `[1,3]`.
- `[2,6]`: 2 ≤ 3 → merge → `[1,6]`.
- `[8,10]`: 8 > 6 → new interval → `[1,6],[8,10]`.
- `[15,18]`: 15 > 10 → new interval → `[1,6],[8,10],[15,18]`.

Result: `[[1,6],[8,10],[15,18]]`.

## Complexity
- Time: O(n log n) for the sort; the merge pass itself is O(n).
- Space: O(n) for the output (or O(log n) extra for the sort).

## Edge Cases
- Single interval → returned unchanged.
- All intervals overlap into one → single merged interval in the result.
- Intervals that merely touch (e.g. `[1,4]` and `[4,5]`) → still merged since the
  condition uses `<=`.
