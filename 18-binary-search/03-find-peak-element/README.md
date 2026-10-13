# Find Peak Element

**Difficulty:** Medium | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/find-peak-element/

## Problem Understanding
A peak is an element strictly greater than its neighbors (edges are compared against `-infinity`). Find the index of **any** peak in O(log n).

## Approach
Binary search on the slope: if `nums[mid] > nums[mid+1]`, the sequence is descending at `mid`, so a peak must exist at `mid` or to its left (keep `hi = mid`). Otherwise it is ascending or flat-up, so a peak must exist to the right (`lo = mid+1`). This always converges because the array edges act as `-infinity`.

## Algorithm
1. `lo = 0`, `hi = n-1`.
2. While `lo < hi`: compare `nums[mid]` to `nums[mid+1]`.
3. Descending → search left half (`hi = mid`); ascending → search right half (`lo = mid+1`).
4. Return `lo`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[1,2,1,3,5,6,4]`: comparisons steer the search toward index 5 (value 6), a valid peak.

## Complexity
- Time: O(log n)
- Space: O(1)

## Edge Cases
- Strictly increasing array → the last index is the peak.
- Strictly decreasing array → the first index is the peak.
- Single element → trivially a peak.
