# Summary Ranges

**Difficulty:** Easy | **Category:** Intervals
**LeetCode:** https://leetcode.com/problems/summary-ranges/

## Problem Understanding
Given a sorted array of unique integers, return the smallest sorted list of ranges
that exactly covers every number. A single number is its own range; a run of
consecutive numbers becomes `"start->end"`.

## Approach
Single pass: for each starting position, extend as far as possible while the next
number is exactly one more than the current, then emit either a single number or a
range string depending on whether the run had length 1.

## Algorithm
1. `i = 0`.
2. While `i < n`: remember `start = i`; extend `i` while `nums[i+1] == nums[i] + 1`.
3. If `start == i` (run of length 1), emit `str(nums[start])`; else emit
   `"{nums[start]}->{nums[i]}"`.
4. Advance `i` past the run and repeat.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The inner `while` greedily extends the current run as far as consecutive values
  allow, using sortedness + uniqueness to guarantee "consecutive value" == "adjacent
  index."
- The `start == i` check distinguishes a length-1 run (single number output) from a
  longer run (range output).

## Dry Run
`nums = [0,1,2,4,5,7]`

- start=0: extends through 1,2 (i=2). Range "0->2".
- start=3 (i=3): nums[4]=5=4+1, extend (i=4). Range "4->5".
- start=5 (i=5): no extension. Single "7".

Result: `["0->2","4->5","7"]`.

## Complexity
- Time: O(n)
- Space: O(1) extra (excluding output).

## Edge Cases
- Empty array → returns `[]`.
- Single element → one single-number range.
- All numbers consecutive → one big range covering everything.
