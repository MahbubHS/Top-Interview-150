# Word Search II

**Difficulty:** Hard | **Category:** Trie
**LeetCode:** https://leetcode.com/problems/word-search-ii/

## Problem Understanding
Given a letter grid and a list of words, return all words that can be formed by walking through adjacent (up/down/left/right) cells without reusing a cell within a word.

## Approach
Running a separate Word Search DFS per word is too slow. Put **all words in a trie** and do one DFS from each cell that follows trie edges: a path is only extended while it is still a prefix of some word. When a node marks a full word, record it (and clear the marker so it is reported once).

## Algorithm
1. Build a trie of the words; store the full word at its end node.
2. DFS from every cell; stop if the letter is not a child of the current trie node.
3. On reaching a word-end node, add the word to the result and clear the marker.
4. Mark the cell visited (`#`) during recursion and restore it afterwards.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Board `[[o,a,a,n],[e,t,a,e],[i,h,k,r],[i,f,l,v]]`, words `[oath,pea,eat,rain]` → `oath` and `eat` are found.

## Complexity
- Time: O(rows × cols × 4 × 3^(L-1)) in the worst case, heavily pruned by the trie
- Space: O(total characters in words)

## Edge Cases
- Duplicate paths to the same word are reported once.
- Words longer than any possible path are pruned immediately.
