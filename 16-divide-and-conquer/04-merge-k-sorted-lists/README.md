# Merge k Sorted Lists

**Difficulty:** Hard | **Category:** Divide & Conquer
**LeetCode:** https://leetcode.com/problems/merge-k-sorted-lists/

## Problem Understanding
Merge `k` sorted linked lists into a single sorted list.

## Approach
**Pairwise divide and conquer.** Merging two sorted lists is cheap and already solved (Merge Two
Sorted Lists). Instead of merging the lists one at a time into a growing result (O(k × n) worst case),
repeatedly merge lists in **pairs**, halving the number of lists each round — the same idea as the
merge step of merge sort, applied at the list-of-lists level.

## Algorithm
1. If `lists` is empty, return null.
2. While more than one list remains: merge adjacent pairs `(lists[0],lists[1]), (lists[2],lists[3]),
   ...` (the last one alone if the count is odd), producing a new, half-as-long list of merged lists.
3. Once only one list remains, return it.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Pairing adjacent lists each round means after `log2(k)` rounds only one list remains, and every
  node is involved in exactly `log2(k)` merge operations total rather than up to `k`.
- The `_merge` helper is the identical two-pointer merge from Merge Two Sorted Lists.

## Dry Run
`lists = [[1,4,5],[1,3,4],[2,6]]`

- Round 1: merge (list0,list1) → `1,1,3,4,4,5`; list2 alone → `2,6`. Now 2 lists.
- Round 2: merge those → `1,1,2,3,4,4,5,6`.

## Complexity
- Time: O(N log k) where N is the total number of nodes across all lists.
- Space: O(log k) for the list-of-lists bookkeeping (merging itself is O(1) extra per pair).

## Edge Cases
- Empty input array → null.
- A mix including some empty lists (`null` entries) → `_merge` handles a null side directly.
- Single list → returned after one trivial "merge" with nothing.
