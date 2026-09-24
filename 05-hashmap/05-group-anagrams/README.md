# Group Anagrams

**Difficulty:** Medium | **Category:** Hashmap
**LeetCode:** https://leetcode.com/problems/group-anagrams/

## Problem Understanding
Group an array of strings so that all anagrams of each other end up in the same group.
Order of groups/words in the output doesn't matter.

## Approach
Anagrams share the same sorted character sequence. Use that sorted sequence as a hash
map key, and bucket each original word into the group for its key.

## Algorithm
1. For each word, compute its sorted-character key (e.g. "eat" → "aet").
2. Append the word to `groups[key]`.
3. Return all the map's values as the list of groups.

## Code
See `Solution.py`, `Solution.cpp`, `Solution.java`.

## Line-by-Line Explanation
- `tuple(sorted(word))` / sorting the char array is what canonicalizes anagrams to an
  identical key — any permutation of the same letters produces the same sorted result.
- A hash map naturally handles arbitrary numbers of distinct groups without needing to
  know them in advance.

## Dry Run
`strs = ["eat","tea","tan","ate","nat","bat"]`

Keys: "eat"→"aet", "tea"→"aet", "tan"→"ant", "ate"→"aet", "nat"→"ant", "bat"→"abt".

Groups: `{"aet": [eat,tea,ate], "ant": [tan,nat], "abt": [bat]}` →
`[["eat","tea","ate"],["tan","nat"],["bat"]]` (order may vary).

## Complexity
- Time: O(n * k log k) where n = number of words, k = max word length (sorting each
  word dominates).
- Space: O(n * k) for the map and output.

## Edge Cases
- Single word input → one group containing that word.
- All words are anagrams of each other → single group with everything.
- Empty string in the input → its key is the empty tuple/string, grouped with any
  other empty strings.
