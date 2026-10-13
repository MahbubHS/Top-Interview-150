# Longest Palindromic Substring

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/longest-palindromic-substring/

## Problem Understanding
Find the longest contiguous substring of `s` that reads the same forwards and backwards.

## Approach
**Expand around center.** Every palindrome has a center — either a single character (odd length) or a gap between two characters (even length). Try all `2n-1` centers, expanding outward while characters match, and keep the widest span found.

## Algorithm
1. For each index `i`, expand around the odd center `(i, i)` and the even center `(i, i+1)`.
2. `expand(l, r)`: grow outward while `s[l] == s[r]`; return the final valid bounds (one step back from where it broke).
3. Track the best `(start, end)` span seen across all centers.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`s = "babad"`: expanding around index 1 ('a') with odd center → "bab"; around index 2 → "aba". Either length-3 answer is valid — this implementation returns `"bab"`.

## Complexity
- Time: O(n²) worst case (each of 2n-1 centers can expand up to O(n))
- Space: O(1) extra (excluding the output substring)

## Edge Cases
- Empty string → `""`.
- Single character → itself.
- Entire string is a palindrome → found via the center in the middle.
