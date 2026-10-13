# Kth Largest Element in an Array

**Difficulty:** Medium | **Category:** Heap
**LeetCode:** https://leetcode.com/problems/kth-largest-element-in-an-array/

## Problem Understanding
Find the k-th largest element in an unsorted array (k-th in sorted-descending order), without necessarily sorting the whole array.

## Approach
Maintain a **min-heap of size k** holding the k largest elements seen so far. Its smallest element (the heap top) is always the k-th largest among everything processed, because anything smaller than the heap top can never make it into the top k.

## Algorithm
1. Build a min-heap from the first `k` elements.
2. For each remaining element, if it beats the heap top (current weakest of the top k), pop the top and push the new element.
3. After processing everything, the heap top is the answer.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[3,2,1,5,6,4]`, k=2: heap starts `{3,2}` (min-heap, top=2). 1 doesn't beat 2. 5>2 → swap, heap `{3,5}`, top=3. 6>3 → swap, heap `{5,6}`, top=5. 4 doesn't beat 5. Answer `5`.

## Complexity
- Time: O(n log k)
- Space: O(k)

## Edge Cases
- `k = 1` → the overall maximum.
- `k = n` → the overall minimum.
- Duplicate values → handled naturally by the heap, no special casing.
