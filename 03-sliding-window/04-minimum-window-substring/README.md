# Minimum Window Substring

**Difficulty:** Hard | **Category:** Sliding Window
**LeetCode:** https://leetcode.com/problems/minimum-window-substring/

## Problem Understanding
Find the smallest substring of `s` that contains every character of `t` (including
duplicates — e.g. if `t = "aab"`, the window needs at least two `'a'`s and one `'b'`).
Return `""` if no such window exists.

## Approach
**Classic expand/contract sliding window.** Maintain a `need` map (how many more of
each character are still required — can go negative once satisfied and beyond) and a
`missing` counter (how many total characters are still unmet). Expand the window right
until `missing == 0` (window is valid), then greedily contract from the left as far as
possible while staying valid, recording the best (smallest) window found.

## Algorithm
1. Build `need` from `t`; `missing = len(t)`.
2. For each `r` (1-indexed end), consume `s[r-1]`: if it was still needed
   (`need[c] > 0`), decrement `missing`; always decrement `need[c]`.
3. Whenever `missing == 0`: shrink `l` while the character leaving is a "surplus"
   (`need[s[l]] < 0`); record the window if it's the best so far; then release one
   required character from the left (making the window invalid again) and advance `l`.
4. Return the best window found, or `""` if none.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `need[c] > 0` before decrementing is what correctly counts only characters that were
  still genuinely required, not ones we already have plenty of.
- `need[s[l]] < 0` during shrink identifies characters currently in surplus — safe to
  drop without breaking validity.
- After recording a valid window, deliberately un-satisfying one required character
  and advancing `l` forces the window to keep sliding for the next candidate.

## Dry Run
`s = "ADOBECODEBANC"`, `t = "ABC"`

The window expands until it first contains A, B, and C (`"ADOBEC"`), then contracts
from the left while still valid, eventually finding the minimal valid window later in
the scan.

Result: `"BANC"`.

## Complexity
- Time: O(|s| + |t|) — each character of `s` is visited by `r` once and by `l` at most
  once.
- Space: O(charset size) for the `need` map.

## Edge Cases
- `t` longer than `s` → no valid window possible, returns `""`.
- `t` has repeated characters → correctly requires that many repeats in the window
  (handled by the signed `need` counts, not a simple set).
- No valid window exists at all → `bestR` stays 0, returns `""`.
