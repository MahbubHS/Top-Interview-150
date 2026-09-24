# Contains Duplicate II

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/contains-duplicate-ii/

## Problem Understanding
Check whether there are two equal values `nums[i]` and `nums[j]` with
`abs(i - j) <= k`.

## Approach
Track the **most recent index** each value was seen at in a hash map. For each new
element, if it was seen before within the last `k` indices, we're done.

## Algorithm
1. `last_index = {}`.
2. For each index `i` with value `num`: if `num` is in `last_index` and
   `i - last_index[num] <= k`, return True.
3. Otherwise (or after), update `last_index[num] = i`.
4. Return False if the loop completes.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Always storing the **most recent** index (overwriting on every occurrence) is what
  keeps the distance check `i - last_index[num]` as tight as possible — using the
  first occurrence instead could miss a valid nearby pair later on.

## Dry Run
`nums = [1,2,3,1]`, `k = 3`

| i | num | last_index[num] | i-last | match? |
|---|-----|------------------|--------|--------|
| 0 | 1 | - | - | no, store 1:0 |
| 1 | 2 | - | - | no, store 2:1 |
| 2 | 3 | - | - | no, store 3:2 |
| 3 | 1 | 0 | 3-0=3 ≤3 | yes! |

Result: `True`.

## Complexity
- Time: O(n)
- Space: O(min(n, distinct values))

## Edge Cases
- `k = 0` → only literally identical indices could match, which never happens for
  distinct i,j → effectively always False unless duplicate values are adjacent... 
  actually k=0 means only i==j qualifies, so always False for i≠j.
- No duplicates at all → returns False.
