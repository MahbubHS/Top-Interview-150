# Find Minimum in Rotated Sorted Array

**Difficulty:** Medium | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

## Problem Understanding
A sorted array (distinct values) was rotated at an unknown pivot. Find the minimum element in O(log n).

## Approach
Compare `nums[mid]` to `nums[hi]`. If `nums[mid] > nums[hi]`, the minimum must be strictly to the right of `mid` (the rotation point is in `[mid+1, hi]`). Otherwise `[lo..mid]` is already sorted and contains the minimum, so keep `mid` in range (`hi = mid`).

## Algorithm
1. `lo = 0`, `hi = n-1`.
2. While `lo < hi`: if `nums[mid] > nums[hi]`, the minimum is to the right → `lo = mid+1`.
3. Else the minimum is at `mid` or to its left → `hi = mid`.
4. Return `nums[lo]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[4,5,6,7,0,1,2]`: mid=3 (7) > nums[hi]=2 → go right; continues narrowing down to index 4 (value 0).

## Complexity
- Time: O(log n)
- Space: O(1)

## Edge Cases
- No rotation → converges immediately to index 0.
- Rotation point at the very end → still found correctly since comparisons always use `nums[hi]`, not a fixed reference.
