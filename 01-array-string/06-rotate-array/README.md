# Rotate Array

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/rotate-array/

## Problem Understanding
Rotate `nums` to the right by `k` steps, in place, using O(1) extra space.

## Approach
**Triple reversal trick.** Reversing the whole array, then reversing each of the two
resulting segments separately, produces a right rotation. Intuition: reversing the
whole array puts the last `k` elements first but in reverse order; reversing the first
`k` and the remaining `n-k` fixes each segment's internal order.

## Algorithm
1. `k %= n` (handle `k > n`).
2. Reverse the entire array.
3. Reverse the first `k` elements.
4. Reverse the remaining `n - k` elements.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `k %= n`: rotating by a multiple of `n` is a no-op, so this normalizes `k`.
- Full reverse flips the whole sequence.
- The two follow-up reverses each restore local order within the rotated halves.

## Dry Run
`nums = [1,2,3,4,5,6,7]`, `k = 3`

1. Reverse all: `[7,6,5,4,3,2,1]`
2. Reverse first 3: `[5,6,7,4,3,2,1]`
3. Reverse last 4: `[5,6,7,1,2,3,4]`

Result: `[5,6,7,1,2,3,4]` — matches rotating right by 3.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- `k == 0` or `k` a multiple of `n` → array unchanged.
- `k > n` → handled by the modulo.
- Single-element array → any rotation is a no-op.
