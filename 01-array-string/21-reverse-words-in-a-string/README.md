# Reverse Words in a String

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/reverse-words-in-a-string/

## Problem Understanding
Reverse the order of words in a string. Words are separated by one or more spaces;
leading/trailing/multiple spaces must be collapsed to single spaces in the output.

## Approach
Split the string on whitespace (which naturally discards empty tokens from extra
spaces), reverse the resulting list of words, then rejoin with single spaces.

## Algorithm
1. Split `s` into words, ignoring extra whitespace.
2. Reverse the list of words.
3. Join with single spaces.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.
(C++ uses `istringstream` to tokenize; Java uses a regex split on `\s+` after
trimming.)

## Line-by-Line Explanation
- Tokenizing via whitespace-splitting is what handles multiple/leading/trailing spaces
  "for free" — empty tokens between consecutive spaces are never produced.
- Reversing the token list then joining with single spaces produces the required
  cleaned-up output format.

## Dry Run
`s = "  hello   world  "`

Tokenize → `["hello", "world"]`
Reverse → `["world", "hello"]`
Join → `"world hello"`.

## Complexity
- Time: O(n)
- Space: O(n) for the token list.

## Edge Cases
- Single word with surrounding spaces → output is just that word, no spaces.
- Multiple consecutive spaces between words → collapsed to one in the output.
