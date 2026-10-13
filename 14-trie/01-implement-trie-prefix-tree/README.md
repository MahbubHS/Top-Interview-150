# Implement Trie (Prefix Tree)

**Difficulty:** Medium | **Category:** Trie
**LeetCode:** https://leetcode.com/problems/implement-trie-prefix-tree/

## Problem Understanding
Build a prefix tree supporting `insert(word)`, `search(word)` (exact word present) and `startsWith(prefix)`.

## Approach
A trie stores one character per edge so words sharing a prefix share a path. Each node has children by letter and a flag marking "a word ends here". Searching and prefix-checking both just follow the letters; the only difference is whether the final node must be marked as a word end.

## Algorithm
1. `insert`: walk/create a child per character, mark the last node as an end.
2. `search`: follow the characters; succeed only if the final node is an end.
3. `startsWith`: follow the characters; succeed if the path exists.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Insert "apple": `search("apple")` → true, `search("app")` → false, `startsWith("app")` → true; insert "app" then `search("app")` → true.

## Complexity
- Time: O(L) per operation for a word of length L
- Space: O(total characters inserted)

## Edge Cases
- Empty prefix → always true (root exists).
- A word that is only a prefix of another is not found by `search` until inserted itself.
