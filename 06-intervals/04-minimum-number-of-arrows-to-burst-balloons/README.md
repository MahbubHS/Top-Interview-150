# Minimum Number of Arrows to Burst Balloons

**Difficulty:** Medium | **Category:** Intervals
**LeetCode:** https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

## Problem Understanding
Each balloon spans `[start, end]` on the x-axis. An arrow shot at x bursts every
balloon whose range includes x. Find the minimum number of arrows to burst all
balloons.

## Approach
**Greedy by end point.** Sort balloons by their end coordinate. Shoot the first arrow
at the end of the first balloon — this greedily bursts every balloon overlapping that
point too. Any balloon whose start is beyond the current arrow's position needs a new
arrow, placed at *its* end (again to maximize how many future balloons it can also
burst).

## Algorithm
1. Sort `points` by end value.
2. `arrows = 1`, `arrow_pos = points[0][1]`.
3. For each subsequent balloon: if its start is beyond `arrow_pos` (doesn't overlap
   the current arrow), shoot a new arrow at its end and update `arrow_pos`.
4. Return `arrows`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Sorting by **end** (not start) is the crucial choice: placing each arrow at the
  earliest possible end coordinate maximizes the chance of also bursting later
  balloons whose ranges extend leftward into that point.
- `start > arrow_pos` is the exact "no longer overlapping the last arrow" condition,
  since the sort guarantees every earlier-processed balloon already has end
  `<= arrow_pos` before we even started grouping around it.

## Dry Run
`points = [[10,16],[2,8],[1,6],[7,12]]` → sorted by end: `[[1,6],[7,12],[10,16],[2,8]]`
→ actually sorted: `[1,6],[2,8],[7,12],[10,16]`

- arrows=1, arrow_pos=6 (from [1,6]).
- `[2,8]`: start 2 ≤ 6 → still bursts, no new arrow.
- `[7,12]`: start 7 > 6 → new arrow at pos=12, arrows=2.
- `[10,16]`: start 10 ≤ 12 → still bursts, no new arrow.

Result: `2`.

## Complexity
- Time: O(n log n) for the sort.
- Space: O(1) extra (or O(log n)/O(n) depending on sort implementation).

## Edge Cases
- No balloons → 0 arrows needed.
- All balloons overlap at a common point → 1 arrow suffices.
- No balloons overlap at all → arrows needed equals the number of balloons.
