# Longest Substring Without Repeating Characters

**Difficulty:** Medium | **Category:** Sliding Window
**LeetCode:** https://leetcode.com/problems/longest-substring-without-repeating-characters/

## Problem Understanding
Find the length of the longest substring that contains no repeated characters.

## Approach
**Sliding window with a "last seen index" map.** Expand the window's right edge one
character at a time. If that character was already seen *inside* the current window,
jump the left edge to just past its previous occurrence — this is an O(1) jump instead
of shrinking one character at a time.

## Algorithm
1. `last_seen = {}`, `l = 0`, `best = 0`.
2. For each index `r` with character `c`: if `c` was seen at an index `>= l`, move
   `l` to `last_seen[c] + 1`.
3. Update `last_seen[c] = r`.
4. Update `best = max(best, r - l + 1)`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The `>= l` check is essential: a character seen *before* the current window started
  is irrelevant and must not incorrectly shrink the window.
- Recording `last_seen[c] = r` after the check ensures we compare against the
  *previous* occurrence, not the one we're currently processing.

## Dry Run
`s = "abcabcbb"`

| r | c | last_seen[c] | l after | window len |
|---|---|---------------|---------|------------|
| 0 | a | - | 0 | 1 |
| 1 | b | - | 0 | 2 |
| 2 | c | - | 0 | 3 |
| 3 | a | 0 (≥0) | 1 | 3 |
| 4 | b | 1 (≥1) | 2 | 3 |
| 5 | c | 2 (≥2) | 3 | 3 |
| 6 | b | 4 (≥3) | 5 | 2 |
| 7 | b | 6 (≥5) | 7 | 1 |

Result: `3` (`"abc"`).

## Complexity
- Time: O(n) — each character visited once by `r`, `l` only moves forward.
- Space: O(min(n, charset size)) for the map.

## Edge Cases
- Empty string → returns 0.
- All identical characters (e.g. `"bbbb"`) → answer is 1.
- All unique characters → answer equals the string length.
