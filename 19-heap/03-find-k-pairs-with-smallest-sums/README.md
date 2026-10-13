# Find K Pairs with Smallest Sums

**Difficulty:** Medium | **Category:** Heap
**LeetCode:** https://leetcode.com/problems/find-k-pairs-with-smallest-sums/

## Problem Understanding
Given two sorted arrays, find the `k` pairs `(nums1[i], nums2[j])` with the smallest sums.

## Approach
Think of it like merging k sorted lists: pairing a fixed `nums1[i]` with `nums2[0], nums2[1], ...` gives a sorted-by-sum sequence. Seed a min-heap with each `nums1[i]` paired with `nums2[0]` (capped at `k` starting pairs, since we never need more than k candidates at once), then repeatedly pop the smallest sum and push that same `i`'s next partner `(i, j+1)`.

## Algorithm
1. Seed the heap with `(nums1[i] + nums2[0], i, 0)` for `i` up to `min(k, len(nums1))`.
2. Pop the smallest-sum entry, record the pair, and — if more of `nums2` remains for that `i` — push `(i, j+1)`.
3. Stop once `k` pairs are collected or the heap empties.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`nums1=[1,7,11]`, `nums2=[2,4,6]`, k=3 → smallest sums give `[1,2],[1,4],[1,6]`.

## Complexity
- Time: O(k log(min(k, m)))
- Space: O(min(k, m))

## Edge Cases
- `k` larger than `m*n` → naturally stops once all pairs are exhausted (heap empties).
- One array empty → `[]`.
