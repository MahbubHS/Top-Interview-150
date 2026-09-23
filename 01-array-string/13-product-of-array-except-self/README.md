# Product of Array Except Self

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/product-of-array-except-self/

## Problem Understanding
Return an array where `res[i]` is the product of all elements except `nums[i]`,
without using division and in O(n) time.

## Approach
`res[i] = (product of everything left of i) * (product of everything right of i)`.
Compute prefix products in one pass, then multiply in suffix products in a second pass
— reusing the output array itself to avoid extra space (beyond the O(1) running
`left`/`right` accumulators).

## Algorithm
1. Left-to-right pass: `res[i] = left`, then `left *= nums[i]`.
2. Right-to-left pass: `res[i] *= right`, then `right *= nums[i]`.
3. Return `res`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- After pass 1, `res[i]` holds the product of all elements strictly to the left of `i`.
- Pass 2 multiplies in the product of all elements strictly to the right of `i`,
  completing the "except self" product.

## Dry Run
`nums = [1,2,3,4]`

Left pass: `res = [1,1,2,6]`, final `left=24`
Right pass:
- i=3: res[3]=6*1=6, right=4
- i=2: res[2]=2*4=8, right=12
- i=1: res[1]=1*12=12, right=24
- i=0: res[0]=1*24=24, right=24

Result: `[24,12,8,6]`.

## Complexity
- Time: O(n) — two linear passes.
- Space: O(1) extra (output array doesn't count).

## Edge Cases
- Array contains a `0`: handled correctly since no division is used — exactly one
  zero makes every `res[i]` except that index equal to 0.
- Two or more zeros: every `res[i]` becomes 0.
