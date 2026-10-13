# Search a 2D Matrix

**Difficulty:** Medium | **Category:** Binary Search
**LeetCode:** https://leetcode.com/problems/search-a-2d-matrix/

## Problem Understanding
Search for `target` in a matrix where each row is sorted and each row's first element is greater than the previous row's last element — meaning the whole matrix reads as one sorted sequence left-to-right, top-to-bottom.

## Approach
Since the matrix is really a single sorted array in disguise, binary search it as one array of length `rows × cols`, converting a flat index `mid` to `(mid / cols, mid % cols)` to read the actual value.

## Algorithm
1. `lo = 0`, `hi = rows*cols - 1`.
2. Standard binary search: compute `mid`, map it to `matrix[mid/cols][mid%cols]`, compare to target.
3. Narrow the range accordingly; return true on an exact match, false if the range empties.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[[1,3,5,7],[10,11,16,20],[23,30,34,60]]`, target 3 → flat index 1 → `matrix[0][1] = 3` → found.

## Complexity
- Time: O(log(rows × cols))
- Space: O(1)

## Edge Cases
- Target smaller than matrix[0][0] or larger than the last element → false.
- Single row or single column → degenerates to ordinary 1D binary search.
