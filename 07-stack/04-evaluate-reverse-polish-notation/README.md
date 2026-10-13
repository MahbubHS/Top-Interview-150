# Evaluate Reverse Polish Notation

**Difficulty:** Medium | **Category:** Stack
**LeetCode:** https://leetcode.com/problems/evaluate-reverse-polish-notation/

## Problem Understanding
Evaluate an arithmetic expression given in postfix (Reverse Polish) notation, where
operators follow their operands (e.g. `["2","1","+","3","*"]` = `(2+1)*3 = 9`).

## Approach
**Stack-based evaluation** — the natural fit for postfix notation. Push numbers.
When an operator is seen, pop the top two operands (the second-popped is the *first*
operand, since it was pushed earlier), apply the operator, and push the result back.

## Algorithm
1. For each token: if it's an operator, pop `b` (pushed most recently = right
   operand), then pop `a` (left operand), compute `a OP b`, push the result.
2. If it's a number, push it (parsed as an integer).
3. The final stack top is the answer.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)
Division must **truncate toward zero** (e.g. `-7 / 2 = -3`, not `-4`). C++/Java's
built-in integer division already does this; Python's `int(a / b)` is used instead of
`//` specifically to match that truncation behavior for negative results.

## Line-by-Line Explanation
- Popping `b` before `a` matters for non-commutative operators (`-`, `/`): the operand
  pushed *second* (more recently) is the right-hand side of the operation.
- The final `stack[-1]` (or equivalent) holds the fully-reduced result once every
  token has been processed.

## Dry Run
`tokens = ["4","13","5","/","+"]`

- push 4 → [4]
- push 13 → [4,13]
- push 5 → [4,13,5]
- "/" : b=5, a=13 → 13/5=2 (truncated) → push 2 → [4,2]
- "+" : b=2, a=4 → 4+2=6 → push 6 → [6]

Result: `6`.

## Complexity
- Time: O(n) — each token processed once.
- Space: O(n) for the stack.

## Edge Cases
- Expression is a single number → stack ends with just that value, no operators
  processed.
- Division resulting in a negative fraction → truncation toward zero handled
  explicitly (not floor division).
