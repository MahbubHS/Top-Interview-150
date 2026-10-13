# Word Break

**Difficulty:** Medium | **Category:** 1D DP
**LeetCode:** https://leetcode.com/problems/word-break/

## Problem Understanding
Check whether `s` can be segmented into a space-separated sequence of one or more dictionary words (words may repeat).

## Approach
`dp[i]` means "the prefix `s[0:i]` can be fully segmented." It is true if there is some earlier valid cut point `j` (`dp[j]` true) such that the remaining chunk `s[j:i]` is itself a dictionary word. Building `dp` left to right reuses previously solved prefixes instead of re-checking from scratch.

## Algorithm
1. `dp[0] = True` (empty prefix trivially breaks).
2. For each end position `i`: try every earlier cut `j`; if `dp[j]` is true and `s[j:i]` is a word, set `dp[i] = True`.
3. Return `dp[n]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`s="leetcode"`, dict=`{"leet","code"}`: `dp[4]=True` (via "leet"), then `dp[8]=True` via `j=4` and `s[4:8]="code"`.

## Complexity
- Time: O(n²) substring checks (O(n³) if substring slicing cost counted, but typically treated as O(n²) with hashing)
- Space: O(n) for dp plus the word set

## Edge Cases
- Empty string → trivially `True` (`dp[0]`).
- No valid segmentation exists → `dp[n]` stays `False`.
