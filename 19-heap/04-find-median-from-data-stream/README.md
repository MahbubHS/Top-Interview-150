# Find Median from Data Stream

**Difficulty:** Hard | **Category:** Heap
**LeetCode:** https://leetcode.com/problems/find-median-from-data-stream/

## Problem Understanding
Support adding numbers one at a time and querying the median of all numbers seen so far, efficiently.

## Approach
Split the data into two heaps: a max-heap `small` holding the lower half, and a min-heap `large` holding the upper half, kept balanced in size (differing by at most 1). The median is then always derivable from the tops of the two heaps in O(1) — no sorting needed on each query.

## Algorithm
1. `addNum`: push into `small` first, then move `small`'s max into `large` (this ordering guarantees the new number ends up on the correct side relative to existing elements).
2. Rebalance: if `large` grew bigger than `small`, move its min back to `small`.
3. `findMedian`: if `small` has one extra element, its top is the median; otherwise average the two tops.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Add 1, 2, 3: after each step the heaps stay balanced (`small={1}`→median 1; `small={2},large={... }` balancing gives median 1.5 after adding 2; after adding 3, median 2).

## Complexity
- Time: O(log n) per `addNum`, O(1) per `findMedian`
- Space: O(n)

## Edge Cases
- First number added → trivially the median.
- Many duplicate values → heaps handle duplicates with no special casing.
