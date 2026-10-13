# Search Insert Position

**Difficulty:** Easy | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/search-insert-position/

## Problem Understanding
Find the index of `target` in a sorted array, or the index where it would be inserted to keep the array sorted.

## Approach
This is "find the first index whose value is >= target" — the classic **lower-bound binary search**. Using a half-open range `[lo, hi)` and shrinking it until `lo == hi` lands exactly on that index, whether or not `target` is present.

## Algorithm
1. `lo = 0`, `hi = n`.
2. While `lo < hi`: `mid = (lo+hi)/2`; if `nums[mid] < target`, search the right half (`lo = mid+1`); else search the left half including mid (`hi = mid`).
3. Return `lo`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[1,3,5,6]`, target 5 → finds index `2`. target 2 → narrows to index `1` (insert between 1 and 3).

## Complexity
- Time: O(log n)
- Space: O(1)

## Edge Cases
- Target smaller than every element → `0`.
- Target larger than every element → `n`.
