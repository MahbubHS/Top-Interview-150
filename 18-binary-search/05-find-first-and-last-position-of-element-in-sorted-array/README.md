# Find First and Last Position of Element in Sorted Array

**Difficulty:** Medium | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

## Problem Understanding
Find the first and last index of `target` in a sorted array (which may contain duplicates), in O(log n), or `[-1,-1]` if absent.

## Approach
Reuse **lower_bound** (first index with value `>= x`) twice: `lower_bound(target)` gives the start; `lower_bound(target + 1) - 1` gives the end (the position just before the first value exceeding target). This avoids writing a separate "upper bound" search from scratch.

## Algorithm
1. `start = lower_bound(target)`.
2. If `start` is out of range or `nums[start] != target`, the value is absent → `[-1,-1]`.
3. `end = lower_bound(target + 1) - 1`.
4. Return `[start, end]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[5,7,7,8,8,10]`, target 8 → `lower_bound(8)=3`, `lower_bound(9)=5` → `[3, 4]`.

## Complexity
- Time: O(log n)
- Space: O(1)

## Edge Cases
- Target absent entirely → `[-1,-1]`.
- Target appears exactly once → `start == end`.
- All elements equal target → `[0, n-1]`.
