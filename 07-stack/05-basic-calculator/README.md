# Basic Calculator

**Difficulty:** Hard | **Category:** Stack
**LeetCode:** https://leetcode.com/problems/basic-calculator/

## Problem Understanding
Evaluate a string expression containing non-negative integers, `+`, `-`, parentheses,
and spaces (no `*`/`/`). Standard operator precedence with `+`/`-` only, left to right,
respecting parentheses.

## Approach
**Single pass with a stack for parenthesis context.** Track a running `result`, the
`number` currently being built (digits accumulate here), and the `sign` to apply to
the *next* completed number. On `(`, push the current `result` and `sign` so they can
be restored (and combined) once the matching `)` closes; on `)`, finalize the number
inside, then pop back the saved sign/result and fold the parenthesized value in.

## Algorithm
1. For each character:
   - Digit: `number = number*10 + digit`.
   - `+`/`-`: fold `sign * number` into `result`, reset `number`, set `sign` for the
     *next* term.
   - `(`: push `(result, sign)`, reset both to start fresh inside the parens.
   - `)`: fold `sign * number` into `result` (finishing the group), then pop the saved
     sign and outer result, combining: `result = savedResult + savedSign * result`.
2. After the loop, fold in any trailing number.
3. Return `result`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)
(C++/Java use `long`/`long long` internally purely as a safety margin against
intermediate overflow on adversarial inputs, then cast back to `int` at the end.)

## Line-by-Line Explanation
- Spaces are implicitly ignored — they don't match any of the `if`/`elif` branches, so
  the loop simply skips over them.
- The two-value push `(result, sign)` on `(` is what lets `)` correctly "undo" into
  the outer context: the popped sign tells us whether the whole parenthesized value
  should be added or subtracted from the outer expression.

## Dry Run
`s = "(1+(4+5+2)-3)+(6+8)"`

Roughly: inner `(4+5+2)` evaluates to 11 within its own `result`; closing that paren
folds it into the outer group as `1 + 11 = 12`; continuing `-3` gives `9`; closing the
outer paren folds `9` into the top-level result; then `+(6+8)` adds `14`.

Result: `23`.

## Complexity
- Time: O(n) — one pass over the string.
- Space: O(n) worst case for the stack (deeply nested parentheses).

## Edge Cases
- Expression starting with a negative-implying `-` at the top level (e.g. `"-2+1"`) —
  handled naturally since `result` starts at 0 and the first `-` just sets sign=-1
  going forward.
- Deeply nested parentheses → stack grows to match nesting depth, unwinds correctly.
- Multi-digit numbers → correctly accumulated via `number*10 + digit` before any
  operator or parenthesis is hit.
