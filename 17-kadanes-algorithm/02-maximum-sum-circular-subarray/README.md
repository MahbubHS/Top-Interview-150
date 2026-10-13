# Maximum Sum Circular Subarray

**Difficulty:** Medium | **Category:** Kadane's Algorithm
**LeetCode:** https://leetcode.com/problems/maximum-sum-circular-subarray/

## Problem Understanding
Same as Maximum Subarray, but the array is circular (a subarray may wrap from the end back to the start). Find the maximum possible sum.

## Approach
The best circular subarray is either (a) a normal non-wrapping subarray — standard Kadane — or (b) a wrapping one, which equals `total sum - (minimum non-wrapping subarray)`, since removing the smallest contiguous chunk from the middle leaves the best wrap-around sum on the outside. Compute both the max and min subarray sums in one pass and combine.

## Algorithm
1. Track running/best max subarray sum (Kadane) and running/best min subarray sum (Kadane for minimum) simultaneously, plus the total sum.
2. If `bestMax < 0` (all numbers negative), the wrap trick would incorrectly give an empty array, so just return `bestMax` directly.
3. Otherwise return `max(bestMax, total - bestMin)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[5,-3,5]`: total=7, bestMax=7 (take all), bestMin=-3 → wrap option = 7-(-3)=10 → answer `10` (wrap: 5+5=10 via the circular 5,_,5).

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- All negative array → must return the single max element via the `bestMax < 0` guard (can't take an empty wrap).
- Single element → that element.
