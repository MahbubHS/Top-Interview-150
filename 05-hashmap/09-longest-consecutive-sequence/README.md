# Longest Consecutive Sequence

**Difficulty:** Medium | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/longest-consecutive-sequence/

## Problem Understanding
Find the length of the longest run of consecutive integers present in the array
(order in the input doesn't matter), in O(n) time — sorting (O(n log n)) is not
allowed as the primary approach.

## Approach
Put all numbers in a hash set for O(1) lookups. The key trick: only start counting a
sequence from a number that is a **sequence start** — i.e. `num - 1` is *not* in the
set. This guarantees each consecutive run is only ever walked once in total (from its
start), giving an overall O(n) instead of O(n²).

## Algorithm
1. Build `num_set` from `nums`.
2. For each `num` in `num_set`: if `num - 1` is not in the set (so `num` starts a
   sequence), count forward (`num+1`, `num+2`, ...) while consecutive values exist.
3. Track the maximum length found.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The `if num - 1 not in num_set` guard is what keeps the algorithm linear overall:
  without it, every element of every run would trigger its own full forward scan,
  causing massive redundant work (e.g. O(n²) on a single long run).
- The `while` loop only executes its full length once per distinct run, across the
  entire outer loop.

## Dry Run
`nums = [100,4,200,1,3,2]` → set = {100,4,200,1,3,2}

- 100: 99 not in set → start. 101 not in set → length 1.
- 4: 3 IS in set → skip (not a start).
- 200: 199 not in set → start. 201 not in set → length 1.
- 1: 0 not in set → start. 2,3,4 in set, 5 not → length 4.
- 3: 2 IS in set → skip.
- 2: 1 IS in set → skip.

Best = `4` (the run `1,2,3,4`).

## Complexity
- Time: O(n) — each number is visited by the inner while loop at most once overall.
- Space: O(n) for the set.

## Edge Cases
- Empty array → returns 0.
- All identical numbers → longest sequence length is 1 (duplicates in the set collapse
  to one entry).
- Already sorted, fully consecutive input → single run of length n.
