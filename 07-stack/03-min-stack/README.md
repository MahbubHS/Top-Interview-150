# Min Stack

**Difficulty:** Medium | **Category:** Stack
**LeetCode:** https://leetcode.com/problems/min-stack/

## Problem Understanding
Design a stack supporting `push`, `pop`, `top`, and `getMin` — all in O(1) time.

## Approach
**Two parallel stacks.** The main stack holds actual values as usual. A second
"min stack" holds, at each position, the minimum value seen *up through that point* in
the main stack. Pushing to both in lockstep, and popping from both together, keeps
`minStack.top()` always equal to the current minimum in O(1), no scanning required.

## Algorithm
- `push(val)`: push to main stack. Push `val` onto `minStack` if it's `<=` the current
  min (new minimum), otherwise re-push the current min (duplicate it) so both stacks
  stay the same height.
- `pop()`: pop both stacks together.
- `top()`: return main stack's top.
- `getMin()`: return min stack's top.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Keeping both stacks the exact same height (even when a value isn't a new minimum)
  is the trick that makes `pop()` trivially correct — popping one element from `stack`
  always corresponds to popping exactly one from `minStack`, restoring the previous
  minimum automatically.
- `val <= minStack.back()` (not strict `<`) correctly handles duplicate minimums:
  pushing an equal value should still be tracked so a later pop of one copy leaves the
  other still recognized as the minimum.

## Dry Run
push(-2): stack=[-2], minStack=[-2]
push(0): stack=[-2,0], minStack=[-2,-2] (0 > -2, duplicate)
push(-3): stack=[-2,0,-3], minStack=[-2,-2,-3] (-3 ≤ -2, new min)
getMin() → -3
pop(): stack=[-2,0], minStack=[-2,-2]
top() → 0
getMin() → -2

## Complexity
- Time: O(1) for every operation.
- Space: O(n) — the min stack doubles memory usage but stays linear.

## Edge Cases
- Pushing the same minimum value multiple times, then popping some → `getMin` stays
  correct throughout thanks to the duplicate-tracking in `minStack`.
- Single-element stack → `top()` and `getMin()` both return that element.
