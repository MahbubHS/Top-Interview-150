# Valid Parentheses

**Difficulty:** Easy | **Category:** Stack
**LeetCode:** https://leetcode.com/problems/valid-parentheses/

## Problem Understanding
Check whether a string of `()[]{}`  is validly matched: every closing bracket closes
the most recently opened bracket of the matching type, and everything gets closed by
the end.

## Approach
**Stack.** Push opening brackets. On a closing bracket, it must match whatever is on
top of the stack (the most recently unmatched opener) — if not, or if the stack is
empty, the string is invalid. At the end, the stack must be empty (no unmatched
openers left).

## Algorithm
1. Map each closing bracket to its matching opener.
2. For each character: if it's a closing bracket, pop and compare to the expected
   opener (fail if stack empty or mismatch); otherwise push it (it's an opener).
3. Return whether the stack is empty at the end.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The stack's LIFO order is exactly what "most recently opened, must close first"
  requires — this is the defining property of correctly nested brackets.
- `not stack` (Python) / `st.empty()` at the end catches strings like `"((("` where
  every character was an opener that never got closed.

## Dry Run
`s = "{[]}"`

| ch | action | stack |
|----|--------|-------|
| { | push | [{] |
| [ | push | [{,[] |
| ] | pop, matches [ | [{] |
| } | pop, matches { | [] |

Stack empty at end → `True`.

`s = "(]"`: push '(' → stack=['(']. ']' expects '[' but top is '(' → mismatch →
`False`.

## Complexity
- Time: O(n)
- Space: O(n) worst case (all openers).

## Edge Cases
- Empty string → trivially valid (empty stack throughout).
- Closing bracket with empty stack (e.g. `")"`) → immediately False.
- Unmatched openers remaining (e.g. `"((("`) → stack non-empty at end → False.
