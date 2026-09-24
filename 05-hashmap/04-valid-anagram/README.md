# Valid Anagram

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/valid-anagram/

## Problem Understanding
Check if `t` is an anagram of `s` — same characters, same multiplicities, any order.

## Approach
Count character frequencies in `s`, then subtract frequencies for each character in
`t`. If everything cancels out to zero (and no count ever goes negative), it's a valid
anagram. Python's `Counter` equality check does this concisely.

## Algorithm
1. If lengths differ, return False immediately.
2. Build a frequency count of `s`.
3. For each character in `t`, decrement its count; if it goes negative, fail.
4. Return True if the scan completes.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.
(Python leverages `Counter` equality for brevity; C++/Java use the explicit
build-then-decrement pattern for clarity and consistent O(n) behavior.)

## Line-by-Line Explanation
- Decrementing counts from `s`'s frequency map while scanning `t` verifies both
  "same characters" and "same multiplicities" in a single pass, without a second map.

## Dry Run
`s = "anagram"`, `t = "nagaram"`

Both strings have identical letter frequencies (a:3, n:1, g:1, r:1, m:1) → counts fully
cancel to zero → `True`.

`s = "rat"`, `t = "car"`: 'c' never appears in `s`'s count → decrementing it goes
negative → `False`.

## Complexity
- Time: O(n)
- Space: O(1) — bounded alphabet size (26 for lowercase English letters).

## Edge Cases
- Different lengths → immediate False, no need to count.
- Empty strings → trivially anagrams of each other.
