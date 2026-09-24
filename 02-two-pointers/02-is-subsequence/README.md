# Is Subsequence

**Difficulty:** Easy | **Category:** Two Pointers
**LeetCode:** https://leetcode.com/problems/is-subsequence/

## Problem Understanding
Check whether `s` can be obtained by deleting some (possibly zero) characters from
`t`, without reordering the rest.

## Approach
Single forward pointer into `s`. Walk through `t` once; whenever the current character
of `t` matches the character `s` is waiting for, advance the `s` pointer. If the
pointer reaches the end of `s`, every character was matched in order.

## Algorithm
1. `i = 0` (pointer into `s`).
2. For each character `c` in `t`: if `i < len(s)` and `s[i] == c`, increment `i`.
3. Return whether `i == len(s)`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- We only ever advance `i`, never look back — greedily matching the earliest possible
  position in `t` for each character of `s` is always at least as good as matching
  later.

## Dry Run
`s = "abc"`, `t = "ahbgdc"`

| c in t | matches s[i]? | i after |
|--------|---------------|---------|
| a | yes (s[0]='a') | 1 |
| h | no | 1 |
| b | yes (s[1]='b') | 2 |
| g | no | 2 |
| d | no | 2 |
| c | yes (s[2]='c') | 3 |

`i == 3 == len(s)` → `True`.

## Complexity
- Time: O(len(t))
- Space: O(1)

## Edge Cases
- `s` is empty → trivially True (i starts and ends at 0).
- `s` longer than `t` → loop can never fully advance `i`, returns False.
