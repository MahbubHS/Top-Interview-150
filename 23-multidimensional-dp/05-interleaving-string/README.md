# Interleaving String

**Difficulty:** Medium | **Category:** Multidimensional DP
**LeetCode:** https://leetcode.com/problems/interleaving-string/

## Problem Understanding
Check whether `s3` can be formed by interleaving `s1` and `s2` (preserving the internal order of each, but freely interspersing them).

## Approach
`dp[i][j]` means "the first `i` characters of `s1` and first `j` characters of `s2` can interleave to form the first `i+j` characters of `s3`." It is reachable from `dp[i-1][j]` (the next `s3` character came from `s1`) or `dp[i][j-1]` (it came from `s2`), whichever matches.

## Algorithm
1. Quick length check: `len(s1)+len(s2)` must equal `len(s3)`, else immediately `False`.
2. `dp[0][0] = True` (two empty prefixes make an empty result).
3. For each `(i,j)`: if `s1[i-1]` matches the next `s3` character, OR in `dp[i-1][j]`; if `s2[j-1]` matches, OR in `dp[i][j-1]`.
4. Return `dp[m][n]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`s1="aabcc"`, `s2="dbbca"`, `s3="aadbbcbcac"` → `True` (a valid interleaving exists); changing `s3`'s last two characters makes it `False`.

## Complexity
- Time: O(m × n)
- Space: O(m × n) (reducible to O(min(m,n)) with a rolling row)

## Edge Cases
- Either `s1` or `s2` empty → `s3` must equal the other exactly.
- Length mismatch → short-circuits to `False` without filling the table.
