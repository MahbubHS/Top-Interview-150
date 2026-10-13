# Design Add and Search Words Data Structure

**Difficulty:** Medium | **Category:** Trie
**LeetCode:** https://leetcode.com/problems/design-add-and-search-words-data-structure/

## Problem Understanding
Support `addWord(word)` and `search(word)`, where `search` may contain `.` that matches any single letter.

## Approach
Use a trie for storage. A normal letter follows one child; a `.` must try **every** child, so `search` becomes a DFS that branches at each wildcard and succeeds if any branch reaches a word-end node at the end of the pattern.

## Algorithm
1. `addWord`: insert into the trie and mark the end.
2. `search`: DFS on (node, index).
3. At index == length, return whether the node is a word end.
4. On `.`, try all children; otherwise follow the single matching child.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
After adding "bad","dad","mad": `search("pad")` → false, `search("b..")` → true (bad).

## Complexity
- Time: Add: O(L). Search: O(L) without wildcards, up to O(26^k · L) with k wildcards
- Space: O(total characters)

## Edge Cases
- All-wildcard pattern such as `"..."` matches any 3-letter word.
- Pattern longer than any stored word → false.
