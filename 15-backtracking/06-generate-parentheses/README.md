# Generate Parentheses

**Difficulty:** Medium | **Category:** Backtracking
**LeetCode:** https://leetcode.com/problems/generate-parentheses/

## Problem Understanding
Return all well-formed strings of `n` pairs of parentheses.

## Approach
Build the string character by character, only making moves that can still lead to a valid result: add `(` while fewer than `n` have been used, and add `)` only while it would not exceed the number of `(` already placed. This pruning means every completed string is automatically valid.

## Algorithm
1. Track `open_count` and `close_count`.
2. If the path has length `2n`, save it.
3. If `open_count < n`, try `(`.
4. If `close_count < open_count`, try `)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`n = 3` → `((())), (()()), (())(), ()(()), ()()()` (5 strings, the 3rd Catalan number).

## Complexity
- Time: O(4^n / √n)
- Space: O(n) recursion + output

## Edge Cases
- `n = 1` → `["()"]`.
- A `)` is never placed before its matching `(`.
