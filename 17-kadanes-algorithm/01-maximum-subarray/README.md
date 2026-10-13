# Maximum Subarray

**Difficulty:** Medium | **Category:** Kadane's Algorithm
**LeetCode:** https://leetcode.com/problems/maximum-subarray/

## Problem Understanding
Find the contiguous subarray with the largest sum, and return that sum.

## Approach
**Kadane's algorithm.** At each position decide: either extend the running subarray by including this element, or start fresh here — whichever gives a larger sum. A negative running sum is never worth carrying forward.

## Algorithm
1. Initialize `best = cur = nums[0]`.
2. For each later element: `cur = max(num, cur + num)` (extend or restart).
3. Update `best = max(best, cur)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[-2,1,-3,4,-1,2,1,-5,4]`: running sums move to 4, 3, 5, 6 around the `4,-1,2,1` block → best `6`.

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- All negative numbers → answer is the single largest (least negative) element.
- Single element → that element.
