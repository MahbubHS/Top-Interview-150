# Length of Last Word

**Difficulty:** Easy | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/length-of-last-word/

## Problem Understanding
Return the length of the last word in a string (words separated by spaces; may have
trailing spaces).

## Approach
Scan from the **end** of the string: first skip trailing spaces, then count characters
until the next space (or start of string).

## Algorithm
1. Move a pointer `i` from the end, skipping spaces.
2. From there, count consecutive non-space characters.
3. Return the count.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.
(Python's `str.split()` conveniently discards empty tokens from extra whitespace,
giving a one-line solution.)

## Line-by-Line Explanation
- The first `while` loop handles any trailing spaces before the last word.
- The second `while` loop measures the word itself, stopping at a space or the string's
  start.

## Dry Run
`s = "   fly me   to   the moon  "`

Skip trailing spaces → land on `'n'` of "moon". Count backward through "moon" → 4
characters, then hit a space. Result: `4`.

## Complexity
- Time: O(n) worst case (e.g., all trailing spaces).
- Space: O(1) for the C++/Java pointer approach; O(n) for Python's `split()`.

## Edge Cases
- String with only one word and no spaces → returns its full length.
- Trailing spaces after the last word → correctly skipped before counting.
