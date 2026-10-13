# Longest Increasing Subsequence

**Difficulty:** Medium | **Category:** 1D DP
**LeetCode:** https://leetcode.com/problems/longest-increasing-subsequence/

## Problem Understanding
Find the length of the longest strictly increasing subsequence (elements need not be contiguous).

## Approach
**Patience sorting with binary search**, achieving O(n log n) instead of the naive O(n²) DP. Maintain `tails[k]` = the smallest possible tail value of an increasing subsequence of length `k+1`. For each new number, binary search for its position: it either extends the longest subsequence so far (appended) or improves (lowers) the tail of some existing length, which keeps future extensions easier without ever shrinking the achievable length.

## Algorithm
1. `tails = []`.
2. For each number, binary search (`lower_bound`) for the first tail `>= num`.
3. If none found, `num` extends the longest subsequence → append it.
4. Otherwise it replaces that tail, keeping the subsequence-of-that-length as "easy to extend" as possible.
5. The final length of `tails` is the LIS length.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`[10,9,2,5,3,7,101,18]`: tails evolves `[10]→[9]→[2]→[2,5]→[2,3]→[2,3,7]→[2,3,7,101]→[2,3,7,18]` → length `4`.

## Complexity
- Time: O(n log n)
- Space: O(n) for the `tails` array

## Edge Cases
- `tails` does not represent an actual LIS itself, only tracks lengths — only its final length is meaningful.
- Strictly decreasing input → `tails` always has length 1 (constantly replaced).
- Single element → LIS length 1.
