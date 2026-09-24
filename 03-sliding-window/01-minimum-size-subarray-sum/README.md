# Minimum Size Subarray Sum

**Difficulty:** Medium | **Category:** Sliding Window
**LeetCode:** https://leetcode.com/problems/minimum-size-subarray-sum/

## Problem Understanding
Find the length of the shortest contiguous subarray whose sum is `>= target`. Return
0 if no such subarray exists. (Array of positive integers.)

## Approach
**Variable-size sliding window.** Expand the window by moving `r` forward, adding to a
running sum. Whenever the sum is already `>= target`, the window is a valid candidate —
try shrinking it from the left as much as possible while it remains valid, recording
the smallest length seen.

## Algorithm
1. `l = 0`, `total = 0`, `best = infinity`.
2. For each `r`, add `nums[r]` to `total`.
3. While `total >= target`: update `best` with the current window length, then shrink
   by subtracting `nums[l]` and advancing `l`.
4. Return `best` (or 0 if never updated).

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Because all numbers are positive, `total` only decreases as we shrink from the left
  and only increases as we grow from the right — this monotonicity is what makes the
  two-pointer window valid (no need to recheck already-shrunk positions).

## Dry Run
`target = 7`, `nums = [2,3,1,2,4,3]`

Window grows to `[2,3,1,2]` (sum=8 ≥7, len 4) → shrink: drop 2 → sum=6 <7, stop
shrinking, best=4.
Continue growing: add 4 → `[3,1,2,4]` sum=10 ≥7 → shrink: drop 3 → sum=7 ≥7, len 3,
best=3 → drop 1 → sum=6 <7, stop.
Continue growing: add 3 → `[2,4,3]` sum=9≥7 → shrink: drop 2 → sum=7≥7, len2, best=2 →
drop 4 → sum=3<7, stop.

Result: `2` (subarray `[4,3]`).

## Complexity
- Time: O(n) — each element added and removed from the window at most once.
- Space: O(1)

## Edge Cases
- No subarray reaches the target → returns 0.
- A single element already `>= target` → answer is 1.
