# Top Interview 150 — Solutions & Explanations

Source list: https://leetcode.com/studyplan/top-interview-150/

Each completed problem has its own folder containing `Solution.py`, `Solution.cpp`, `Solution.java`, and a `README.md` walking through the problem, approach, algorithm, a dry run, complexity, and edge cases.

> Status legend: ✅ = solved & documented, ⏳ = planned for a follow-up batch.


## Array / String

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Merge Sorted Array | Easy | [Link](https://leetcode.com/problems/merge-sorted-array/) | [Code](./01-array-string/01-merge-sorted-array/) | [Explanation](./01-array-string/01-merge-sorted-array/README.md) | Merge two sorted arrays in place using a back-to-front two-pointer scan. |
| ✅ | Remove Element | Easy | [Link](https://leetcode.com/problems/remove-element/) | [Code](./01-array-string/02-remove-element/) | [Explanation](./01-array-string/02-remove-element/README.md) | Remove all occurrences of a value in place using a write pointer. |
| ✅ | Remove Duplicates from Sorted Array | Easy | [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) | [Code](./01-array-string/03-remove-duplicates-from-sorted-array/) | [Explanation](./01-array-string/03-remove-duplicates-from-sorted-array/README.md) | Deduplicate a sorted array in place, keeping one copy of each value. |
| ✅ | Remove Duplicates from Sorted Array II | Medium | [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/) | [Code](./01-array-string/04-remove-duplicates-from-sorted-array-ii/) | [Explanation](./01-array-string/04-remove-duplicates-from-sorted-array-ii/README.md) | Deduplicate a sorted array in place, allowing up to two copies of each value. |
| ✅ | Majority Element | Easy | [Link](https://leetcode.com/problems/majority-element/) | [Code](./01-array-string/05-majority-element/) | [Explanation](./01-array-string/05-majority-element/README.md) | Find the element appearing more than n/2 times using Boyer-Moore voting. |
| ✅ | Rotate Array | Medium | [Link](https://leetcode.com/problems/rotate-array/) | [Code](./01-array-string/06-rotate-array/) | [Explanation](./01-array-string/06-rotate-array/README.md) | Rotate an array right by k using the triple-reversal trick. |
| ✅ | Best Time to Buy and Sell Stock | Easy | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/) | [Code](./01-array-string/07-best-time-to-buy-and-sell-stock/) | [Explanation](./01-array-string/07-best-time-to-buy-and-sell-stock/README.md) | Maximize profit from a single buy/sell transaction. |
| ✅ | Best Time to Buy and Sell Stock II | Medium | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/) | [Code](./01-array-string/08-best-time-to-buy-and-sell-stock-ii/) | [Explanation](./01-array-string/08-best-time-to-buy-and-sell-stock-ii/README.md) | Maximize profit with unlimited transactions by summing every uptick. |
| ✅ | Jump Game | Medium | [Link](https://leetcode.com/problems/jump-game/) | [Code](./01-array-string/09-jump-game/) | [Explanation](./01-array-string/09-jump-game/README.md) | Determine if the last index is reachable using greedy farthest-reach. |
| ✅ | Jump Game II | Medium | [Link](https://leetcode.com/problems/jump-game-ii/) | [Code](./01-array-string/10-jump-game-ii/) | [Explanation](./01-array-string/10-jump-game-ii/README.md) | Find the minimum number of jumps to reach the last index. |
| ✅ | H-Index | Medium | [Link](https://leetcode.com/problems/h-index/) | [Code](./01-array-string/11-h-index/) | [Explanation](./01-array-string/11-h-index/README.md) | Compute a researcher's H-Index from a citations array. |
| ✅ | Insert Delete GetRandom O(1) | Medium | [Link](https://leetcode.com/problems/insert-delete-getrandom-o1/) | [Code](./01-array-string/12-insert-delete-getrandom-o1/) | [Explanation](./01-array-string/12-insert-delete-getrandom-o1/README.md) | Design a set supporting O(1) insert, remove, and uniform random access. |
| ✅ | Product of Array Except Self | Medium | [Link](https://leetcode.com/problems/product-of-array-except-self/) | [Code](./01-array-string/13-product-of-array-except-self/) | [Explanation](./01-array-string/13-product-of-array-except-self/README.md) | Compute products except self using prefix and suffix passes, no division. |
| ✅ | Gas Station | Medium | [Link](https://leetcode.com/problems/gas-station/) | [Code](./01-array-string/14-gas-station/) | [Explanation](./01-array-string/14-gas-station/README.md) | Find the valid starting gas station for a full circular route. |
| ✅ | Candy | Hard | [Link](https://leetcode.com/problems/candy/) | [Code](./01-array-string/15-candy/) | [Explanation](./01-array-string/15-candy/README.md) | Minimize candy distribution while satisfying neighbor rating constraints. |
| ✅ | Trapping Rain Water | Hard | [Link](https://leetcode.com/problems/trapping-rain-water/) | [Code](./01-array-string/16-trapping-rain-water/) | [Explanation](./01-array-string/16-trapping-rain-water/README.md) | Compute trapped rainwater using a two-pointer left/right max approach. |
| ✅ | Roman to Integer | Easy | [Link](https://leetcode.com/problems/roman-to-integer/) | [Code](./01-array-string/17-roman-to-integer/) | [Explanation](./01-array-string/17-roman-to-integer/README.md) | Convert a Roman numeral string to an integer. |
| ✅ | Integer to Roman | Medium | [Link](https://leetcode.com/problems/integer-to-roman/) | [Code](./01-array-string/18-integer-to-roman/) | [Explanation](./01-array-string/18-integer-to-roman/README.md) | Convert an integer to a Roman numeral string. |
| ✅ | Length of Last Word | Easy | [Link](https://leetcode.com/problems/length-of-last-word/) | [Code](./01-array-string/19-length-of-last-word/) | [Explanation](./01-array-string/19-length-of-last-word/README.md) | Find the length of the last word in a string. |
| ✅ | Longest Common Prefix | Easy | [Link](https://leetcode.com/problems/longest-common-prefix/) | [Code](./01-array-string/20-longest-common-prefix/) | [Explanation](./01-array-string/20-longest-common-prefix/README.md) | Find the longest common prefix among an array of strings. |
| ✅ | Reverse Words in a String | Medium | [Link](https://leetcode.com/problems/reverse-words-in-a-string/) | [Code](./01-array-string/21-reverse-words-in-a-string/) | [Explanation](./01-array-string/21-reverse-words-in-a-string/README.md) | Reverse word order in a string, collapsing extra whitespace. |
| ✅ | Zigzag Conversion | Medium | [Link](https://leetcode.com/problems/zigzag-conversion/) | [Code](./01-array-string/22-zigzag-conversion/) | [Explanation](./01-array-string/22-zigzag-conversion/README.md) | Simulate writing a string in a zigzag pattern across rows. |
| ✅ | Find the Index of the First Occurrence in a String | Easy | [Link](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/) | [Code](./01-array-string/23-find-the-index-of-the-first-occurrence-in-a-string/) | [Explanation](./01-array-string/23-find-the-index-of-the-first-occurrence-in-a-string/README.md) | Implement strStr() to find a substring's first index. |
| ✅ | Text Justification | Hard | [Link](https://leetcode.com/problems/text-justification/) | [Code](./01-array-string/24-text-justification/) | [Explanation](./01-array-string/24-text-justification/README.md) | Fully justify lines of text to a fixed width with even space distribution. |

## Two Pointers

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Valid Palindrome | Easy | [Link](https://leetcode.com/problems/valid-palindrome/) | [Code](./02-two-pointers/01-valid-palindrome/) | [Explanation](./02-two-pointers/01-valid-palindrome/README.md) | Check if a string is a palindrome ignoring non-alphanumeric characters. |
| ✅ | Is Subsequence | Easy | [Link](https://leetcode.com/problems/is-subsequence/) | [Code](./02-two-pointers/02-is-subsequence/) | [Explanation](./02-two-pointers/02-is-subsequence/README.md) | Check if one string is a subsequence of another. |
| ✅ | Two Sum II - Input Array Is Sorted | Medium | [Link](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/) | [Code](./02-two-pointers/03-two-sum-ii-input-array-is-sorted/) | [Explanation](./02-two-pointers/03-two-sum-ii-input-array-is-sorted/README.md) | Find two numbers summing to a target in a sorted array. |
| ✅ | Container With Most Water | Medium | [Link](https://leetcode.com/problems/container-with-most-water/) | [Code](./02-two-pointers/04-container-with-most-water/) | [Explanation](./02-two-pointers/04-container-with-most-water/README.md) | Find two lines that form the container holding the most water. |
| ✅ | 3Sum | Medium | [Link](https://leetcode.com/problems/3sum/) | [Code](./02-two-pointers/05-3sum/) | [Explanation](./02-two-pointers/05-3sum/README.md) | Find all unique triplets that sum to zero. |

## Sliding Window

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Minimum Size Subarray Sum | Medium | [Link](https://leetcode.com/problems/minimum-size-subarray-sum/) | [Code](./03-sliding-window/01-minimum-size-subarray-sum/) | [Explanation](./03-sliding-window/01-minimum-size-subarray-sum/README.md) | Find the shortest contiguous subarray with sum at least a target. |
| ✅ | Longest Substring Without Repeating Characters | Medium | [Link](https://leetcode.com/problems/longest-substring-without-repeating-characters/) | [Code](./03-sliding-window/02-longest-substring-without-repeating-characters/) | [Explanation](./03-sliding-window/02-longest-substring-without-repeating-characters/README.md) | Find the longest substring with no repeated characters. |
| ✅ | Substring with Concatenation of All Words | Hard | [Link](https://leetcode.com/problems/substring-with-concatenation-of-all-words/) | [Code](./03-sliding-window/03-substring-with-concatenation-of-all-words/) | [Explanation](./03-sliding-window/03-substring-with-concatenation-of-all-words/README.md) | Find start indices where a concatenation of all given words occurs. |
| ✅ | Minimum Window Substring | Hard | [Link](https://leetcode.com/problems/minimum-window-substring/) | [Code](./03-sliding-window/04-minimum-window-substring/) | [Explanation](./03-sliding-window/04-minimum-window-substring/README.md) | Find the smallest window containing all characters of a target string. |

## Matrix

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Valid Sudoku | Medium | [Link](https://leetcode.com/problems/valid-sudoku/) | [Code](./04-matrix/01-valid-sudoku/) | [Explanation](./04-matrix/01-valid-sudoku/README.md) | Validate a 9x9 Sudoku board's rows, columns, and boxes. |
| ✅ | Spiral Matrix | Medium | [Link](https://leetcode.com/problems/spiral-matrix/) | [Code](./04-matrix/02-spiral-matrix/) | [Explanation](./04-matrix/02-spiral-matrix/README.md) | Return all matrix elements in spiral order. |
| ✅ | Rotate Image | Medium | [Link](https://leetcode.com/problems/rotate-image/) | [Code](./04-matrix/03-rotate-image/) | [Explanation](./04-matrix/03-rotate-image/README.md) | Rotate an n x n matrix 90 degrees in place. |
| ✅ | Set Matrix Zeroes | Medium | [Link](https://leetcode.com/problems/set-matrix-zeroes/) | [Code](./04-matrix/04-set-matrix-zeroes/) | [Explanation](./04-matrix/04-set-matrix-zeroes/README.md) | Zero out entire rows/columns for any zero found, in place. |
| ✅ | Game of Life | Medium | [Link](https://leetcode.com/problems/game-of-life/) | [Code](./04-matrix/05-game-of-life/) | [Explanation](./04-matrix/05-game-of-life/README.md) | Simulate one step of Conway's Game of Life in place. |

## Hashmap

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Ransom Note | Easy | [Link](https://leetcode.com/problems/ransom-note/) | [Code](./05-hashmap/01-ransom-note/) | [Explanation](./05-hashmap/01-ransom-note/README.md) | Check if a ransom note can be built from letters in a magazine. |
| ✅ | Isomorphic Strings | Easy | [Link](https://leetcode.com/problems/isomorphic-strings/) | [Code](./05-hashmap/02-isomorphic-strings/) | [Explanation](./05-hashmap/02-isomorphic-strings/README.md) | Check if two strings follow the same character mapping pattern. |
| ✅ | Word Pattern | Easy | [Link](https://leetcode.com/problems/word-pattern/) | [Code](./05-hashmap/03-word-pattern/) | [Explanation](./05-hashmap/03-word-pattern/README.md) | Check if a string follows the same pattern as a given pattern string. |
| ✅ | Valid Anagram | Easy | [Link](https://leetcode.com/problems/valid-anagram/) | [Code](./05-hashmap/04-valid-anagram/) | [Explanation](./05-hashmap/04-valid-anagram/README.md) | Check if two strings are anagrams of each other. |
| ✅ | Group Anagrams | Medium | [Link](https://leetcode.com/problems/group-anagrams/) | [Code](./05-hashmap/05-group-anagrams/) | [Explanation](./05-hashmap/05-group-anagrams/README.md) | Group an array of strings into sets of anagrams. |
| ✅ | Two Sum | Easy | [Link](https://leetcode.com/problems/two-sum/) | [Code](./05-hashmap/06-two-sum/) | [Explanation](./05-hashmap/06-two-sum/README.md) | Find two indices whose values sum to a target, using a hash map. |
| ✅ | Happy Number | Easy | [Link](https://leetcode.com/problems/happy-number/) | [Code](./05-hashmap/07-happy-number/) | [Explanation](./05-hashmap/07-happy-number/README.md) | Determine if repeated digit-square-sum eventually reaches 1. |
| ✅ | Contains Duplicate II | Easy | [Link](https://leetcode.com/problems/contains-duplicate-ii/) | [Code](./05-hashmap/08-contains-duplicate-ii/) | [Explanation](./05-hashmap/08-contains-duplicate-ii/README.md) | Check for a duplicate value within a given index distance k. |
| ✅ | Longest Consecutive Sequence | Medium | [Link](https://leetcode.com/problems/longest-consecutive-sequence/) | [Code](./05-hashmap/09-longest-consecutive-sequence/) | [Explanation](./05-hashmap/09-longest-consecutive-sequence/README.md) | Find the longest run of consecutive integers in O(n). |

## Intervals

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Summary Ranges | Easy | [Link](https://leetcode.com/problems/summary-ranges/) | [Code](./06-intervals/01-summary-ranges/) | [Explanation](./06-intervals/01-summary-ranges/README.md) | Summarize a sorted array of unique numbers into ranges. |
| ✅ | Merge Intervals | Medium | [Link](https://leetcode.com/problems/merge-intervals/) | [Code](./06-intervals/02-merge-intervals/) | [Explanation](./06-intervals/02-merge-intervals/README.md) | Merge all overlapping intervals. |
| ✅ | Insert Interval | Medium | [Link](https://leetcode.com/problems/insert-interval/) | [Code](./06-intervals/03-insert-interval/) | [Explanation](./06-intervals/03-insert-interval/README.md) | Insert a new interval into a sorted, non-overlapping interval list and merge. |
| ✅ | Minimum Number of Arrows to Burst Balloons | Medium | [Link](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | [Code](./06-intervals/04-minimum-number-of-arrows-to-burst-balloons/) | [Explanation](./06-intervals/04-minimum-number-of-arrows-to-burst-balloons/README.md) | Find the minimum arrows needed to burst all balloons by interval overlap. |

## Stack

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Valid Parentheses | Easy | [Link](https://leetcode.com/problems/valid-parentheses/) | [Code](./07-stack/01-valid-parentheses/) | [Explanation](./07-stack/01-valid-parentheses/README.md) | Check if a string of brackets is validly matched and nested. |
| ✅ | Simplify Path | Medium | [Link](https://leetcode.com/problems/simplify-path/) | [Code](./07-stack/02-simplify-path/) | [Explanation](./07-stack/02-simplify-path/README.md) | Simplify a Unix-style absolute file path. |
| ✅ | Min Stack | Medium | [Link](https://leetcode.com/problems/min-stack/) | [Code](./07-stack/03-min-stack/) | [Explanation](./07-stack/03-min-stack/README.md) | Design a stack supporting push/pop/top/getMin all in O(1). |
| ✅ | Evaluate Reverse Polish Notation | Medium | [Link](https://leetcode.com/problems/evaluate-reverse-polish-notation/) | [Code](./07-stack/04-evaluate-reverse-polish-notation/) | [Explanation](./07-stack/04-evaluate-reverse-polish-notation/README.md) | Evaluate an arithmetic expression given in postfix notation. |
| ✅ | Basic Calculator | Hard | [Link](https://leetcode.com/problems/basic-calculator/) | [Code](./07-stack/05-basic-calculator/) | [Explanation](./07-stack/05-basic-calculator/README.md) | Evaluate a string expression with +, -, parentheses, and spaces. |

## Linked List

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Linked List Cycle | Easy | [Link](https://leetcode.com/problems/linked-list-cycle/) | [Code](./08-linked-list/01-linked-list-cycle/) | [Explanation](./08-linked-list/01-linked-list-cycle/README.md) | Detect a cycle in a linked list using Floyd's tortoise and hare. |
| ✅ | Add Two Numbers | Medium | [Link](https://leetcode.com/problems/add-two-numbers/) | [Code](./08-linked-list/02-add-two-numbers/) | [Explanation](./08-linked-list/02-add-two-numbers/README.md) | Add two numbers represented as reversed-digit linked lists. |
| ✅ | Merge Two Sorted Lists | Easy | [Link](https://leetcode.com/problems/merge-two-sorted-lists/) | [Code](./08-linked-list/03-merge-two-sorted-lists/) | [Explanation](./08-linked-list/03-merge-two-sorted-lists/README.md) | Merge two sorted linked lists into one sorted list. |
| ✅ | Copy List with Random Pointer | Medium | [Link](https://leetcode.com/problems/copy-list-with-random-pointer/) | [Code](./08-linked-list/04-copy-list-with-random-pointer/) | [Explanation](./08-linked-list/04-copy-list-with-random-pointer/README.md) | Deep-copy a linked list where nodes have an extra random pointer. |
| ✅ | Reverse Linked List II | Medium | [Link](https://leetcode.com/problems/reverse-linked-list-ii/) | [Code](./08-linked-list/05-reverse-linked-list-ii/) | [Explanation](./08-linked-list/05-reverse-linked-list-ii/README.md) | Reverse a sublist of a linked list between two positions. |
| ✅ | Reverse Nodes in k-Group | Hard | [Link](https://leetcode.com/problems/reverse-nodes-in-k-group/) | [Code](./08-linked-list/06-reverse-nodes-in-k-group/) | [Explanation](./08-linked-list/06-reverse-nodes-in-k-group/README.md) | Reverse nodes of a linked list k at a time. |
| ✅ | Remove Nth Node From End of List | Medium | [Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/) | [Code](./08-linked-list/07-remove-nth-node-from-end-of-list/) | [Explanation](./08-linked-list/07-remove-nth-node-from-end-of-list/README.md) | Remove the nth node from the end using two pointers. |
| ✅ | Remove Duplicates from Sorted List II | Medium | [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/) | [Code](./08-linked-list/08-remove-duplicates-from-sorted-list-ii/) | [Explanation](./08-linked-list/08-remove-duplicates-from-sorted-list-ii/README.md) | Remove all nodes with duplicate values from a sorted linked list. |
| ✅ | Rotate List | Medium | [Link](https://leetcode.com/problems/rotate-list/) | [Code](./08-linked-list/09-rotate-list/) | [Explanation](./08-linked-list/09-rotate-list/README.md) | Rotate a linked list to the right by k places. |
| ✅ | Partition List | Medium | [Link](https://leetcode.com/problems/partition-list/) | [Code](./08-linked-list/10-partition-list/) | [Explanation](./08-linked-list/10-partition-list/README.md) | Partition a linked list around a value x, preserving relative order. |
| ✅ | LRU Cache | Medium | [Link](https://leetcode.com/problems/lru-cache/) | [Code](./08-linked-list/11-lru-cache/) | [Explanation](./08-linked-list/11-lru-cache/README.md) | Design a Least Recently Used cache with O(1) get and put. |

## Binary Tree General

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Maximum Depth of Binary Tree | Easy | [Link](https://leetcode.com/problems/maximum-depth-of-binary-tree/) | [Code](./09-binary-tree-general/01-maximum-depth-of-binary-tree/) | [Explanation](./09-binary-tree-general/01-maximum-depth-of-binary-tree/README.md) | Find the maximum depth of a binary tree. |
| ✅ | Same Tree | Easy | [Link](https://leetcode.com/problems/same-tree/) | [Code](./09-binary-tree-general/02-same-tree/) | [Explanation](./09-binary-tree-general/02-same-tree/README.md) | Check if two binary trees are structurally identical with equal values. |
| ✅ | Invert Binary Tree | Easy | [Link](https://leetcode.com/problems/invert-binary-tree/) | [Code](./09-binary-tree-general/03-invert-binary-tree/) | [Explanation](./09-binary-tree-general/03-invert-binary-tree/README.md) | Mirror a binary tree by swapping every left/right child. |
| ✅ | Symmetric Tree | Easy | [Link](https://leetcode.com/problems/symmetric-tree/) | [Code](./09-binary-tree-general/04-symmetric-tree/) | [Explanation](./09-binary-tree-general/04-symmetric-tree/README.md) | Check if a binary tree is a mirror of itself. |
| ✅ | Construct Binary Tree from Preorder and Inorder Traversal | Medium | [Link](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/) | [Code](./09-binary-tree-general/05-construct-binary-tree-from-preorder-and-inorder-traversal/) | [Explanation](./09-binary-tree-general/05-construct-binary-tree-from-preorder-and-inorder-traversal/README.md) | Rebuild a binary tree from its preorder and inorder traversals. |
| ✅ | Construct Binary Tree from Inorder and Postorder Traversal | Medium | [Link](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/) | [Code](./09-binary-tree-general/06-construct-binary-tree-from-inorder-and-postorder-traversal/) | [Explanation](./09-binary-tree-general/06-construct-binary-tree-from-inorder-and-postorder-traversal/README.md) | Rebuild a binary tree from its inorder and postorder traversals. |
| ✅ | Populating Next Right Pointers in Each Node II | Medium | [Link](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/) | [Code](./09-binary-tree-general/07-populating-next-right-pointers-in-each-node-ii/) | [Explanation](./09-binary-tree-general/07-populating-next-right-pointers-in-each-node-ii/README.md) | Connect each node to its next right neighbor on any binary tree. |
| ✅ | Flatten Binary Tree to Linked List | Medium | [Link](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/) | [Code](./09-binary-tree-general/08-flatten-binary-tree-to-linked-list/) | [Explanation](./09-binary-tree-general/08-flatten-binary-tree-to-linked-list/README.md) | Flatten a binary tree into a right-skewed linked list in preorder. |
| ✅ | Path Sum | Easy | [Link](https://leetcode.com/problems/path-sum/) | [Code](./09-binary-tree-general/09-path-sum/) | [Explanation](./09-binary-tree-general/09-path-sum/README.md) | Check if a root-to-leaf path sums to a target value. |
| ✅ | Sum Root to Leaf Numbers | Medium | [Link](https://leetcode.com/problems/sum-root-to-leaf-numbers/) | [Code](./09-binary-tree-general/10-sum-root-to-leaf-numbers/) | [Explanation](./09-binary-tree-general/10-sum-root-to-leaf-numbers/README.md) | Sum all numbers formed by root-to-leaf digit paths. |
| ✅ | Binary Tree Maximum Path Sum | Hard | [Link](https://leetcode.com/problems/binary-tree-maximum-path-sum/) | [Code](./09-binary-tree-general/11-binary-tree-maximum-path-sum/) | [Explanation](./09-binary-tree-general/11-binary-tree-maximum-path-sum/README.md) | Find the maximum path sum between any two nodes in a binary tree. |
| ✅ | Binary Search Tree Iterator | Medium | [Link](https://leetcode.com/problems/binary-search-tree-iterator/) | [Code](./09-binary-tree-general/12-binary-search-tree-iterator/) | [Explanation](./09-binary-tree-general/12-binary-search-tree-iterator/README.md) | Design an iterator for in-order traversal of a BST. |
| ✅ | Count Complete Tree Nodes | Medium | [Link](https://leetcode.com/problems/count-complete-tree-nodes/) | [Code](./09-binary-tree-general/13-count-complete-tree-nodes/) | [Explanation](./09-binary-tree-general/13-count-complete-tree-nodes/README.md) | Count nodes in a complete binary tree faster than O(n). |
| ✅ | Lowest Common Ancestor of a Binary Tree | Medium | [Link](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) | [Code](./09-binary-tree-general/14-lowest-common-ancestor-of-a-binary-tree/) | [Explanation](./09-binary-tree-general/14-lowest-common-ancestor-of-a-binary-tree/README.md) | Find the lowest common ancestor of two nodes in a binary tree. |

## Binary Tree BFS

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Binary Tree Right Side View | Medium | [Link](https://leetcode.com/problems/binary-tree-right-side-view/) | [Code](./10-binary-tree-bfs/01-binary-tree-right-side-view/) | [Explanation](./10-binary-tree-bfs/01-binary-tree-right-side-view/README.md) | Return the values visible from the right side of a binary tree. |
| ✅ | Average of Levels in Binary Tree | Easy | [Link](https://leetcode.com/problems/average-of-levels-in-binary-tree/) | [Code](./10-binary-tree-bfs/02-average-of-levels-in-binary-tree/) | [Explanation](./10-binary-tree-bfs/02-average-of-levels-in-binary-tree/README.md) | Compute the average value of nodes at each level. |
| ✅ | Binary Tree Level Order Traversal | Medium | [Link](https://leetcode.com/problems/binary-tree-level-order-traversal/) | [Code](./10-binary-tree-bfs/03-binary-tree-level-order-traversal/) | [Explanation](./10-binary-tree-bfs/03-binary-tree-level-order-traversal/README.md) | Return node values grouped by level, level by level. |
| ✅ | Binary Tree Zigzag Level Order Traversal | Medium | [Link](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/) | [Code](./10-binary-tree-bfs/04-binary-tree-zigzag-level-order-traversal/) | [Explanation](./10-binary-tree-bfs/04-binary-tree-zigzag-level-order-traversal/README.md) | Return level order traversal alternating left-to-right and right-to-left. |

## Binary Search Tree

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Minimum Absolute Difference in BST | Easy | [Link](https://leetcode.com/problems/minimum-absolute-difference-in-bst/) | [Code](./11-binary-search-tree/01-minimum-absolute-difference-in-bst/) | [Explanation](./11-binary-search-tree/01-minimum-absolute-difference-in-bst/README.md) | Find the minimum absolute difference between any two node values in a BST. |
| ✅ | Kth Smallest Element in a BST | Medium | [Link](https://leetcode.com/problems/kth-smallest-element-in-a-bst/) | [Code](./11-binary-search-tree/02-kth-smallest-element-in-a-bst/) | [Explanation](./11-binary-search-tree/02-kth-smallest-element-in-a-bst/README.md) | Find the kth smallest value in a BST using in-order traversal. |
| ✅ | Validate Binary Search Tree | Medium | [Link](https://leetcode.com/problems/validate-binary-search-tree/) | [Code](./11-binary-search-tree/03-validate-binary-search-tree/) | [Explanation](./11-binary-search-tree/03-validate-binary-search-tree/README.md) | Check whether a binary tree satisfies the BST property. |

## Graph General

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Number of Islands | Medium | [Link](https://leetcode.com/problems/number-of-islands/) | [Code](./12-graph-general/01-number-of-islands/) | [Explanation](./12-graph-general/01-number-of-islands/README.md) | Count connected groups of land cells in a grid via DFS/BFS. |
| ✅ | Surrounded Regions | Medium | [Link](https://leetcode.com/problems/surrounded-regions/) | [Code](./12-graph-general/02-surrounded-regions/) | [Explanation](./12-graph-general/02-surrounded-regions/README.md) | Capture regions of 'O's fully surrounded by 'X's. |
| ✅ | Clone Graph | Medium | [Link](https://leetcode.com/problems/clone-graph/) | [Code](./12-graph-general/03-clone-graph/) | [Explanation](./12-graph-general/03-clone-graph/README.md) | Deep-copy a connected undirected graph. |
| ✅ | Evaluate Division | Medium | [Link](https://leetcode.com/problems/evaluate-division/) | [Code](./12-graph-general/04-evaluate-division/) | [Explanation](./12-graph-general/04-evaluate-division/README.md) | Answer division queries modeled as a weighted graph. |
| ✅ | Course Schedule | Medium | [Link](https://leetcode.com/problems/course-schedule/) | [Code](./12-graph-general/05-course-schedule/) | [Explanation](./12-graph-general/05-course-schedule/README.md) | Determine if all courses can be finished given prerequisites (cycle detection). |
| ✅ | Course Schedule II | Medium | [Link](https://leetcode.com/problems/course-schedule-ii/) | [Code](./12-graph-general/06-course-schedule-ii/) | [Explanation](./12-graph-general/06-course-schedule-ii/README.md) | Return a valid course order given prerequisites (topological sort). |

## Graph BFS

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Snakes and Ladders | Medium | [Link](https://leetcode.com/problems/snakes-and-ladders/) | [Code](./13-graph-bfs/01-snakes-and-ladders/) | [Explanation](./13-graph-bfs/01-snakes-and-ladders/README.md) | Find the minimum number of moves to reach the last square via BFS. |
| ✅ | Minimum Genetic Mutation | Medium | [Link](https://leetcode.com/problems/minimum-genetic-mutation/) | [Code](./13-graph-bfs/02-minimum-genetic-mutation/) | [Explanation](./13-graph-bfs/02-minimum-genetic-mutation/README.md) | Find the minimum mutations to transform one gene string to another. |
| ✅ | Word Ladder | Hard | [Link](https://leetcode.com/problems/word-ladder/) | [Code](./13-graph-bfs/03-word-ladder/) | [Explanation](./13-graph-bfs/03-word-ladder/README.md) | Find the shortest transformation sequence length between two words. |

## Trie

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Implement Trie (Prefix Tree) | Medium | [Link](https://leetcode.com/problems/implement-trie-prefix-tree/) | [Code](./14-trie/01-implement-trie-prefix-tree/) | [Explanation](./14-trie/01-implement-trie-prefix-tree/README.md) | Design a trie supporting insert, search, and prefix search. |
| ✅ | Design Add and Search Words Data Structure | Medium | [Link](https://leetcode.com/problems/design-add-and-search-words-data-structure/) | [Code](./14-trie/02-design-add-and-search-words-data-structure/) | [Explanation](./14-trie/02-design-add-and-search-words-data-structure/README.md) | Design a trie-like structure supporting '.' wildcard search. |
| ✅ | Word Search II | Hard | [Link](https://leetcode.com/problems/word-search-ii/) | [Code](./14-trie/03-word-search-ii/) | [Explanation](./14-trie/03-word-search-ii/README.md) | Find all dictionary words present in a letter grid using a trie + DFS. |

## Backtracking

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Letter Combinations of a Phone Number | Medium | [Link](https://leetcode.com/problems/letter-combinations-of-a-phone-number/) | [Code](./15-backtracking/01-letter-combinations-of-a-phone-number/) | [Explanation](./15-backtracking/01-letter-combinations-of-a-phone-number/README.md) | Generate all letter combinations for a digit string on a phone keypad. |
| ✅ | Combinations | Medium | [Link](https://leetcode.com/problems/combinations/) | [Code](./15-backtracking/02-combinations/) | [Explanation](./15-backtracking/02-combinations/README.md) | Generate all combinations of k numbers from 1..n. |
| ✅ | Permutations | Medium | [Link](https://leetcode.com/problems/permutations/) | [Code](./15-backtracking/03-permutations/) | [Explanation](./15-backtracking/03-permutations/README.md) | Generate all permutations of a distinct-integer array. |
| ✅ | Combination Sum | Medium | [Link](https://leetcode.com/problems/combination-sum/) | [Code](./15-backtracking/04-combination-sum/) | [Explanation](./15-backtracking/04-combination-sum/README.md) | Find all combinations that sum to a target, with unlimited reuse. |
| ✅ | N-Queens II | Hard | [Link](https://leetcode.com/problems/n-queens-ii/) | [Code](./15-backtracking/05-n-queens-ii/) | [Explanation](./15-backtracking/05-n-queens-ii/README.md) | Count the number of distinct solutions to the N-Queens puzzle. |
| ✅ | Generate Parentheses | Medium | [Link](https://leetcode.com/problems/generate-parentheses/) | [Code](./15-backtracking/06-generate-parentheses/) | [Explanation](./15-backtracking/06-generate-parentheses/README.md) | Generate all combinations of well-formed parentheses. |
| ✅ | Word Search | Medium | [Link](https://leetcode.com/problems/word-search/) | [Code](./15-backtracking/07-word-search/) | [Explanation](./15-backtracking/07-word-search/README.md) | Check if a word can be constructed from adjacent letters in a grid. |

## Divide & Conquer

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Convert Sorted Array to Binary Search Tree | Easy | [Link](https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/) | [Code](./16-divide-and-conquer/01-convert-sorted-array-to-binary-search-tree/) | [Explanation](./16-divide-and-conquer/01-convert-sorted-array-to-binary-search-tree/README.md) | Build a height-balanced BST from a sorted array. |
| ✅ | Sort List | Medium | [Link](https://leetcode.com/problems/sort-list/) | [Code](./16-divide-and-conquer/02-sort-list/) | [Explanation](./16-divide-and-conquer/02-sort-list/README.md) | Sort a linked list in O(n log n) using merge sort. |
| ✅ | Construct Quad Tree | Medium | [Link](https://leetcode.com/problems/construct-quad-tree/) | [Code](./16-divide-and-conquer/03-construct-quad-tree/) | [Explanation](./16-divide-and-conquer/03-construct-quad-tree/README.md) | Build a quad tree representation of a binary grid. |
| ✅ | Merge k Sorted Lists | Hard | [Link](https://leetcode.com/problems/merge-k-sorted-lists/) | [Code](./16-divide-and-conquer/04-merge-k-sorted-lists/) | [Explanation](./16-divide-and-conquer/04-merge-k-sorted-lists/README.md) | Merge k sorted linked lists into one sorted list. |

## Kadane's Algorithm

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Maximum Subarray | Medium | [Link](https://leetcode.com/problems/maximum-subarray/) | [Code](./17-kadanes-algorithm/01-maximum-subarray/) | [Explanation](./17-kadanes-algorithm/01-maximum-subarray/README.md) | Find the contiguous subarray with the largest sum. |
| ✅ | Maximum Sum Circular Subarray | Medium | [Link](https://leetcode.com/problems/maximum-sum-circular-subarray/) | [Code](./17-kadanes-algorithm/02-maximum-sum-circular-subarray/) | [Explanation](./17-kadanes-algorithm/02-maximum-sum-circular-subarray/README.md) | Find the maximum sum subarray in a circular array. |

## Binary Search

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Search Insert Position | Easy | [Link](https://leetcode.com/problems/search-insert-position/) | [Code](./18-binary-search/01-search-insert-position/) | [Explanation](./18-binary-search/01-search-insert-position/README.md) | Find the index of a target, or its sorted insertion point. |
| ✅ | Search a 2D Matrix | Medium | [Link](https://leetcode.com/problems/search-a-2d-matrix/) | [Code](./18-binary-search/02-search-a-2d-matrix/) | [Explanation](./18-binary-search/02-search-a-2d-matrix/README.md) | Search a target in a row/column sorted matrix treated as a flat array. |
| ✅ | Find Peak Element | Medium | [Link](https://leetcode.com/problems/find-peak-element/) | [Code](./18-binary-search/03-find-peak-element/) | [Explanation](./18-binary-search/03-find-peak-element/README.md) | Find any local peak element in O(log n). |
| ✅ | Search in Rotated Sorted Array | Medium | [Link](https://leetcode.com/problems/search-in-rotated-sorted-array/) | [Code](./18-binary-search/04-search-in-rotated-sorted-array/) | [Explanation](./18-binary-search/04-search-in-rotated-sorted-array/README.md) | Search a target in a rotated sorted array in O(log n). |
| ✅ | Find First and Last Position of Element in Sorted Array | Medium | [Link](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) | [Code](./18-binary-search/05-find-first-and-last-position-of-element-in-sorted-array/) | [Explanation](./18-binary-search/05-find-first-and-last-position-of-element-in-sorted-array/README.md) | Find the start and end index of a target value's range. |
| ✅ | Find Minimum in Rotated Sorted Array | Medium | [Link](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/) | [Code](./18-binary-search/06-find-minimum-in-rotated-sorted-array/) | [Explanation](./18-binary-search/06-find-minimum-in-rotated-sorted-array/README.md) | Find the minimum element in a rotated sorted array. |
| ✅ | Median of Two Sorted Arrays | Hard | [Link](https://leetcode.com/problems/median-of-two-sorted-arrays/) | [Code](./18-binary-search/07-median-of-two-sorted-arrays/) | [Explanation](./18-binary-search/07-median-of-two-sorted-arrays/README.md) | Find the median of two sorted arrays in O(log(min(m,n))). |

## Heap

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Kth Largest Element in an Array | Medium | [Link](https://leetcode.com/problems/kth-largest-element-in-an-array/) | [Code](./19-heap/01-kth-largest-element-in-an-array/) | [Explanation](./19-heap/01-kth-largest-element-in-an-array/README.md) | Find the kth largest element using a min-heap of size k. |
| ✅ | IPO | Hard | [Link](https://leetcode.com/problems/ipo/) | [Code](./19-heap/02-ipo/) | [Explanation](./19-heap/02-ipo/README.md) | Maximize capital by greedily picking affordable, most profitable projects. |
| ✅ | Find K Pairs with Smallest Sums | Medium | [Link](https://leetcode.com/problems/find-k-pairs-with-smallest-sums/) | [Code](./19-heap/03-find-k-pairs-with-smallest-sums/) | [Explanation](./19-heap/03-find-k-pairs-with-smallest-sums/README.md) | Find the k pairs with the smallest sums from two sorted arrays. |
| ✅ | Find Median from Data Stream | Hard | [Link](https://leetcode.com/problems/find-median-from-data-stream/) | [Code](./19-heap/04-find-median-from-data-stream/) | [Explanation](./19-heap/04-find-median-from-data-stream/README.md) | Maintain a running median using two heaps. |

## Bit Manipulation

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Add Binary | Easy | [Link](https://leetcode.com/problems/add-binary/) | [Code](./20-bit-manipulation/01-add-binary/) | [Explanation](./20-bit-manipulation/01-add-binary/README.md) | Add two binary strings and return the sum as a binary string. |
| ✅ | Reverse Bits | Easy | [Link](https://leetcode.com/problems/reverse-bits/) | [Code](./20-bit-manipulation/02-reverse-bits/) | [Explanation](./20-bit-manipulation/02-reverse-bits/README.md) | Reverse the bits of a 32-bit unsigned integer. |
| ✅ | Number of 1 Bits | Easy | [Link](https://leetcode.com/problems/number-of-1-bits/) | [Code](./20-bit-manipulation/03-number-of-1-bits/) | [Explanation](./20-bit-manipulation/03-number-of-1-bits/README.md) | Count the number of set bits in an integer. |
| ✅ | Single Number | Easy | [Link](https://leetcode.com/problems/single-number/) | [Code](./20-bit-manipulation/04-single-number/) | [Explanation](./20-bit-manipulation/04-single-number/README.md) | Find the element that appears once via XOR, all others appear twice. |
| ✅ | Single Number II | Medium | [Link](https://leetcode.com/problems/single-number-ii/) | [Code](./20-bit-manipulation/05-single-number-ii/) | [Explanation](./20-bit-manipulation/05-single-number-ii/README.md) | Find the element appearing once when all others appear exactly three times. |
| ✅ | Bitwise AND of Numbers Range | Medium | [Link](https://leetcode.com/problems/bitwise-and-of-numbers-range/) | [Code](./20-bit-manipulation/06-bitwise-and-of-numbers-range/) | [Explanation](./20-bit-manipulation/06-bitwise-and-of-numbers-range/README.md) | Find the bitwise AND of all numbers in a range [m, n]. |

## Math

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Palindrome Number | Easy | [Link](https://leetcode.com/problems/palindrome-number/) | [Code](./21-math/01-palindrome-number/) | [Explanation](./21-math/01-palindrome-number/README.md) | Check if an integer reads the same forwards and backwards. |
| ✅ | Plus One | Easy | [Link](https://leetcode.com/problems/plus-one/) | [Code](./21-math/02-plus-one/) | [Explanation](./21-math/02-plus-one/README.md) | Increment a large integer represented as a digit array. |
| ✅ | Factorial Trailing Zeroes | Medium | [Link](https://leetcode.com/problems/factorial-trailing-zeroes/) | [Code](./21-math/03-factorial-trailing-zeroes/) | [Explanation](./21-math/03-factorial-trailing-zeroes/README.md) | Count trailing zeroes in n! without computing the factorial. |
| ✅ | Sqrt(x) | Easy | [Link](https://leetcode.com/problems/sqrtx/) | [Code](./21-math/04-sqrtx/) | [Explanation](./21-math/04-sqrtx/README.md) | Compute the integer square root without built-in power functions. |
| ✅ | Pow(x, n) | Medium | [Link](https://leetcode.com/problems/powx-n/) | [Code](./21-math/05-powx-n/) | [Explanation](./21-math/05-powx-n/README.md) | Implement fast exponentiation (x^n) in O(log n). |
| ✅ | Max Points on a Line | Hard | [Link](https://leetcode.com/problems/max-points-on-a-line/) | [Code](./21-math/06-max-points-on-a-line/) | [Explanation](./21-math/06-max-points-on-a-line/README.md) | Find the maximum number of points lying on the same straight line. |

## 1D DP

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Climbing Stairs | Easy | [Link](https://leetcode.com/problems/climbing-stairs/) | [Code](./22-1d-dp/01-climbing-stairs/) | [Explanation](./22-1d-dp/01-climbing-stairs/README.md) | Count distinct ways to climb n stairs taking 1 or 2 steps. |
| ✅ | House Robber | Medium | [Link](https://leetcode.com/problems/house-robber/) | [Code](./22-1d-dp/02-house-robber/) | [Explanation](./22-1d-dp/02-house-robber/README.md) | Maximize loot without robbing two adjacent houses. |
| ✅ | Word Break | Medium | [Link](https://leetcode.com/problems/word-break/) | [Code](./22-1d-dp/03-word-break/) | [Explanation](./22-1d-dp/03-word-break/README.md) | Determine if a string can be segmented into dictionary words. |
| ✅ | Coin Change | Medium | [Link](https://leetcode.com/problems/coin-change/) | [Code](./22-1d-dp/04-coin-change/) | [Explanation](./22-1d-dp/04-coin-change/README.md) | Find the fewest coins needed to make a target amount. |
| ✅ | Longest Increasing Subsequence | Medium | [Link](https://leetcode.com/problems/longest-increasing-subsequence/) | [Code](./22-1d-dp/05-longest-increasing-subsequence/) | [Explanation](./22-1d-dp/05-longest-increasing-subsequence/README.md) | Find the length of the longest strictly increasing subsequence. |

## Multidimensional DP

| Status | Problem | Difficulty | LeetCode | Solution Folder | Explanation | Description |
|---|---|---|---|---|---|---|
| ✅ | Triangle | Medium | [Link](https://leetcode.com/problems/triangle/) | [Code](./23-multidimensional-dp/01-triangle/) | [Explanation](./23-multidimensional-dp/01-triangle/README.md) | Find the minimum path sum from top to bottom of a triangle. |
| ✅ | Minimum Path Sum | Medium | [Link](https://leetcode.com/problems/minimum-path-sum/) | [Code](./23-multidimensional-dp/02-minimum-path-sum/) | [Explanation](./23-multidimensional-dp/02-minimum-path-sum/README.md) | Find the minimum sum path from top-left to bottom-right of a grid. |
| ✅ | Unique Paths II | Medium | [Link](https://leetcode.com/problems/unique-paths-ii/) | [Code](./23-multidimensional-dp/03-unique-paths-ii/) | [Explanation](./23-multidimensional-dp/03-unique-paths-ii/README.md) | Count unique paths through a grid with obstacles. |
| ✅ | Longest Palindromic Substring | Medium | [Link](https://leetcode.com/problems/longest-palindromic-substring/) | [Code](./23-multidimensional-dp/04-longest-palindromic-substring/) | [Explanation](./23-multidimensional-dp/04-longest-palindromic-substring/README.md) | Find the longest palindromic substring of a string. |
| ✅ | Interleaving String | Medium | [Link](https://leetcode.com/problems/interleaving-string/) | [Code](./23-multidimensional-dp/05-interleaving-string/) | [Explanation](./23-multidimensional-dp/05-interleaving-string/README.md) | Check if a string is formed by interleaving two other strings. |
| ✅ | Edit Distance | Medium | [Link](https://leetcode.com/problems/edit-distance/) | [Code](./23-multidimensional-dp/06-edit-distance/) | [Explanation](./23-multidimensional-dp/06-edit-distance/README.md) | Find the minimum operations to convert one string into another. |
| ✅ | Best Time to Buy and Sell Stock III | Hard | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/) | [Code](./23-multidimensional-dp/07-best-time-to-buy-and-sell-stock-iii/) | [Explanation](./23-multidimensional-dp/07-best-time-to-buy-and-sell-stock-iii/README.md) | Maximize profit with at most two transactions. |
| ✅ | Best Time to Buy and Sell Stock IV | Hard | [Link](https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/) | [Code](./23-multidimensional-dp/08-best-time-to-buy-and-sell-stock-iv/) | [Explanation](./23-multidimensional-dp/08-best-time-to-buy-and-sell-stock-iv/README.md) | Maximize profit with at most k transactions. |
| ✅ | Maximal Square | Medium | [Link](https://leetcode.com/problems/maximal-square/) | [Code](./23-multidimensional-dp/09-maximal-square/) | [Explanation](./23-multidimensional-dp/09-maximal-square/README.md) | Find the largest square of 1s in a binary matrix using DP. |
