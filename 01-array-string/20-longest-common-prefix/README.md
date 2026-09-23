# Longest Common Prefix

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/longest-common-prefix/

## Problem Understanding
Find the longest string that is a prefix of every string in the input array. Return
`""` if none exists.

## Approach
**Horizontal shrinking.** Start with the first string as a candidate prefix. For each
subsequent string, shrink the candidate from the back until it actually is a prefix of
that string.

## Algorithm
1. If the array is empty, return `""`.
2. `prefix = strs[0]`.
3. For each remaining string `s`, while `prefix` is not a prefix of `s`, chop the last
   character off `prefix`. If `prefix` becomes empty, return `""` immediately.
4. Return the final `prefix`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- The inner `while` loop only ever shortens `prefix`, so it terminates in at most
  `len(prefix)` steps per string.
- Early-exit on empty prefix avoids scanning remaining strings once we know the answer
  is `""`.

## Dry Run
`strs = ["flower","flow","flight"]`

- `prefix = "flower"`
- vs "flow": not a prefix → shrink to "flowe", "flow" → matches.
- vs "flight": "flow" not a prefix → shrink to "flo", "fl" → matches "flight".

Result: `"fl"`.

## Complexity
- Time: O(S) where S is the sum of all character counts in the worst case.
- Space: O(1) extra (excluding the output string).

## Edge Cases
- Single string in array → that whole string is the answer.
- Empty string present in the array → immediately forces result to `""`.
