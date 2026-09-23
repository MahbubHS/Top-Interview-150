# Find the Index of the First Occurrence in a String

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/

## Problem Understanding
Implement `strStr()`: return the index of the first occurrence of `needle` in
`haystack`, or -1 if `needle` is not a substring.

## Approach
**Brute-force sliding window.** Try every starting index `i` in `haystack` where a
needle-length substring still fits, and compare directly. This is O(n*m) worst case but
simple and sufficient for typical constraints (KMP would improve to O(n+m) if needed).

## Algorithm
1. For `i` from 0 to `n-m` (inclusive), check if `haystack[i:i+m] == needle`.
2. Return the first matching `i`.
3. If no match found, return -1.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The loop bound `i + m <= n` ensures we never slice past the end of `haystack`.
- Substring comparison at each position is the core check; as soon as one matches we
  return immediately.

## Dry Run
`haystack = "sadbutsad"`, `needle = "sad"`

- i=0: "sad" == "sad" → match! Return `0`.

For `needle = "leeto"`: no substring of `haystack` ever equals it → return `-1`.

## Complexity
- Time: O(n*m) worst case (brute force); O(n+m) achievable with KMP.
- Space: O(1) (excluding substring temporaries).

## Edge Cases
- `needle` is empty → by LeetCode convention, return 0 (not explicitly handled above
  since constraints guarantee `needle.length >= 1`).
- `needle` longer than `haystack` → loop never executes, returns -1.
