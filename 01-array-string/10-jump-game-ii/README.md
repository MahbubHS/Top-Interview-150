# Jump Game II

**Difficulty:** Medium | **Category:** Array / String
**LeetCode:** https://leetcode.com/problems/jump-game-ii/

## Problem Understanding
Same setup as Jump Game, but now return the **minimum number of jumps** to reach the
last index (guaranteed reachable).

## Approach
**BFS-style greedy / "layers".** Think of it as BFS on implicit levels: `curEnd` marks
the boundary of the current jump's reach; `farthest` tracks the best reach achievable
from anywhere within the current layer. When `i` reaches `curEnd`, we're forced to take
another jump, so we commit to `farthest` as the new boundary.

## Algorithm
1. `jumps = 0`, `curEnd = 0`, `farthest = 0`.
2. For `i` from 0 to n-2: update `farthest = max(farthest, i + nums[i])`.
3. If `i == curEnd`: increment `jumps`, set `curEnd = farthest`.
4. Return `jumps`.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- We stop the loop at `n-2` (not `n-1`) since once we can reach the last index we don't
  need to "jump from" it.
- `i == curEnd` means we've exhausted every index reachable with the current jump
  count, forcing the next jump.

## Dry Run
`nums = [2,3,1,1,4]`

| i | nums[i] | farthest | i==curEnd? | jumps | curEnd |
|---|---------|----------|------------|-------|--------|
| 0 | 2 | 2 | yes (0==0) | 1 | 2 |
| 1 | 3 | 4 | no | 1 | 2 |
| 2 | 1 | 4 | yes (2==2) | 2 | 4 |
| 3 | 1 | 4 | no | 2 | 4 |

Result: `2` (0→1→4).

## Complexity
- Time: O(n)
- Space: O(1)

## Edge Cases
- Array of length 1 → 0 jumps needed.
- `nums[0]` alone reaches the end → still counted as exactly 1 jump.
