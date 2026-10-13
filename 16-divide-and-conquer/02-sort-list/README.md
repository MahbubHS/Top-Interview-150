# Sort List

**Difficulty:** Medium | **Category:** Divide & Conquer
**LeetCode:** https://leetcode.com/problems/sort-list/

## Problem Understanding
Sort a linked list in O(n log n) time (ideally O(1) extra space beyond recursion).

## Approach
**Merge sort**, the natural O(n log n) choice for linked lists since merging two sorted lists needs
no random access (unlike quicksort's partitioning). Split the list in half using slow/fast pointers,
recursively sort each half, then merge the two sorted halves.

## Algorithm
1. Base case: 0 or 1 node → already sorted.
2. Find the middle with slow/fast pointers (fast starts one step ahead so the split is clean); cut the
   list into two halves.
3. Recursively `sortList` each half.
4. Merge the two sorted halves (identical to Merge Two Sorted Lists).

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- Starting `fast = head.next` (not `head`) makes `slow` land on the last node of the *first* half for
  even-length lists, giving a clean split with no shared node.
- Cutting `slow.next = None` before recursing is essential — otherwise the "first half" would still be
  linked to the second half.

## Dry Run
`head = 4->2->1->3`

Split → `4->2` and `1->3`. Sort each: `2->4` and `1->3`. Merge: `1->2->3->4`.

## Complexity
- Time: O(n log n)
- Space: O(log n) recursion stack (merging itself is O(1) extra).

## Edge Cases
- Empty or single-node list → returned unchanged.
- Already sorted list → merge steps still run but produce the same order.
- Duplicate values → `<=` in the merge keeps the sort stable.
