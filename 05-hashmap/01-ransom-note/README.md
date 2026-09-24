# Ransom Note

**Difficulty:** Easy | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/ransom-note/

## Problem Understanding
Determine if `ransomNote` can be constructed using letters from `magazine`, where each
letter in `magazine` can be used at most once.

## Approach
Count each character's availability in `magazine`. Then, for each character needed in
`ransomNote`, consume one from the count; if any count would go negative, it's
impossible.

## Algorithm
1. Build a frequency map of `magazine`.
2. For each character in `ransomNote`, decrement its count in the map.
3. If any count drops below 0, return False immediately.
4. If the scan completes, return True.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- Decrementing directly in the magazine's frequency map (rather than building a
  separate ransom-note count) naturally models "each letter used at most once."

## Dry Run
`ransomNote = "aa"`, `magazine = "aab"`

magCount = {a:2, b:1}. Consume 'a' → a:1. Consume 'a' → a:0. Never negative → `True`.

For `ransomNote = "aa"`, `magazine = "ab"`: magCount={a:1,b:1}. Consume 'a'→a:0.
Consume 'a'→a:-1 → `False`.

## Complexity
- Time: O(|magazine| + |ransomNote|)
- Space: O(1) — at most 26 lowercase letters.

## Edge Cases
- Empty `ransomNote` → trivially True (nothing to construct).
- `magazine` shorter than `ransomNote` → guaranteed False at some point.
