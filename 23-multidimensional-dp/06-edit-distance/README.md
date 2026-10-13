# Edit Distance

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/edit-distance/

## Problem Understanding
Find the minimum number of insert/delete/replace operations to transform `word1` into `word2`.

## Approach
Classic 2D DP: `dp[i][j]` is the edit distance between the first `i` characters of `word1` and first `j` of `word2`. If the current characters match, no operation is needed there — inherit `dp[i-1][j-1]`. Otherwise take the best of the three possible single operations (replace, delete from word1, insert into word1) and add 1.

## Algorithm
1. Base cases: transforming an empty string into a length-`k` string costs `k` insertions (`dp[0][j]=j`, `dp[i][0]=i`).
2. If characters match, `dp[i][j] = dp[i-1][j-1]` (free).
3. Otherwise `dp[i][j] = 1 + min(dp[i-1][j-1]` [replace]`, dp[i-1][j]` [delete]`, dp[i][j-1]` [insert]`)`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`word1="horse"`, `word2="ros"`: known answer `3` (replace h→r, delete r, delete e — one valid sequence among the optimal ones).

## Complexity
- Time: O(m × n)
- Space: O(m × n) (reducible to O(min(m,n)) with a rolling row)

## Edge Cases
- One string empty → distance equals the other string's length.
- Identical strings → distance 0.
