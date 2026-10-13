# Insert Interval

**Difficulty:** Medium | **Category:** Intervals
**LeetCode:** https://leetcode.com/problems/insert-interval/

## Problem Understanding
Given a list of non-overlapping intervals sorted by start, insert a new interval and
merge as needed so the result stays non-overlapping and sorted.

## Approach
Three-phase linear scan since the input is already sorted: (1) copy every interval
that ends entirely before the new one starts — no overlap possible; (2) merge every
interval that overlaps the new one (expanding its bounds); (3) copy every remaining
interval, which necessarily starts after the merged interval ends.

## Algorithm
1. While `intervals[i]` ends before `newInterval` starts, copy it as-is.
2. While `intervals[i]` starts at or before the (growing) merged interval's end,
   absorb it — extend `start`/`end` to cover it.
3. Append the final merged `[start, end]`.
4. Copy all remaining intervals unchanged.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Phase 1's condition `intervals[i][1] < newInterval[0]` is a strict "no overlap, no
  touch" check — anything satisfying it can never merge with the new interval.
- Phase 2's condition `intervals[i][0] <= end` re-checks against the *currently
  growing* `end`, not just the original `newInterval[1]`, so it correctly keeps
  absorbing a chain of overlapping intervals.

## Dry Run
`intervals = [[1,3],[6,9]]`, `newInterval = [2,5]`

- Phase 1: `[1,3]` ends at 3, not `< 2` → stop immediately (i=0).
- Phase 2: start=2,end=5. `[1,3]`: 1≤5 → absorb → start=1,end=5, i=1.
  `[6,9]`: 6≤5? no → stop.
- Append `[1,5]`.
- Phase 3: copy `[6,9]`.

Result: `[[1,5],[6,9]]`.

## Complexity
- Time: O(n) — single linear pass, no sorting needed since input is already sorted.
- Space: O(n) for the output.

## Edge Cases
- New interval overlaps nothing → simply inserted in its sorted position (phases 1
  and 3 do all the work, phase 2 loop body never executes beyond appending itself).
- New interval swallows every existing interval → phase 2 absorbs everything, result
  is just `[newInterval]` expanded to cover all.
- Empty `intervals` input → result is just `[newInterval]`.
