# Search in Rotated Sorted Array

**Difficulty:** Medium | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/search-in-rotated-sorted-array/

## Problem Understanding
A sorted array was rotated at an unknown pivot. Find the index of `target` in O(log n), or -1.

## Approach
At every `mid`, **at least one half is still normally sorted** (either `[lo..mid]` or `[mid..hi]`). Check which half is sorted by comparing `nums[lo]` to `nums[mid]`, then determine whether `target` falls inside that sorted half's range; if so recurse there, otherwise recurse into the other half.

## Algorithm
1. Standard `lo <= hi` binary search; return `mid` on exact match.
2. If `nums[lo] <= nums[mid]`, the left half is sorted: narrow to it if `target` is within `[nums[lo], nums[mid])`, else go right.
3. Otherwise the right half is sorted: narrow to it if `target` is within `(nums[mid], nums[hi]]`, else go left.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[4,5,6,7,0,1,2]`, target 0: mid=3 (value 7); left half `[4..7]` sorted but 0 not in `[4,7)` → go right → eventually lands on index 4.

## Complexity
- Time: O(log n)
- Space: O(1)

## Edge Cases
- No rotation (already sorted) → behaves like plain binary search.
- Target not present → returns -1.
- Single element → trivial check.
