# LRU Cache

**Difficulty:** Medium | **Category:** Linked List
**LeetCode:** https://leetcode.com/problems/lru-cache/

## Problem Understanding
Design a fixed-capacity cache supporting `get(key)` and `put(key, value)`, both in
O(1) average time. When capacity is exceeded, evict the **least recently used** item
(the one that hasn't been accessed — by get or put — for the longest time).

## Approach
**Hash map + doubly linked list.** The hash map gives O(1) lookup from key to the
corresponding list node. The doubly linked list maintains recency order: the front is
"most recently used," the back is "least recently used." Every access (`get` or
`put`) moves the touched node to the front; when the cache overflows, the node just
before the tail sentinel (the true least-recently-used node) is evicted.

## Algorithm
- Maintain two dummy sentinel nodes, `head` and `tail`, so every real node always has
  both neighbors defined — no null-checking needed for splicing.
- `_remove(node)`: unlink a node from wherever it currently sits (O(1), since it's a
  doubly linked list).
- `_add_to_front(node)`: insert a node immediately after `head` (marks it
  most-recently-used).
- `get(key)`: if absent, return -1. Otherwise remove-then-re-add-to-front (refreshes
  recency), return the value.
- `put(key, value)`: if the key exists, remove its old node first. Create/insert a new
  node at the front. If capacity is now exceeded, evict `tail.prev` (the actual LRU
  node) from both the list and the map.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Line-by-Line Explanation
- The sentinel `head`/`tail` nodes are what make `_remove` and `_add_to_front`
  branch-free — every real node always has a non-null `prev` and `next` to relink.
- Storing `Node` objects (not just values) in the hash map is the key link between the
  two structures: it lets `get` jump straight to a node's position in the list without
  any traversal.

## Dry Run
`LRUCache(2)`
- put(1,1): cache={1}, list: 1
- put(2,2): cache={1,2}, list: 2->1
- get(1) → 1; list becomes: 1->2 (1 refreshed to front)
- put(3,3): capacity exceeded (would be 3 items) → evict LRU (2, at the back) →
  list: 3->1, cache={1,3}
- get(2) → -1 (evicted)
- put(4,4): evict LRU (1) → list: 4->3, cache={3,4}
- get(1) → -1
- get(3) → 3
- get(4) → 4

## Complexity
- Time: O(1) for both `get` and `put`.
- Space: O(capacity) for the map and list nodes.

## Edge Cases
- `put` on an existing key → updates its value and refreshes it to most-recently-used
  (old node removed, new node added at front — equivalent to an update-in-place).
- Capacity of 1 → every `put` immediately evicts whatever was there before (once a
  second distinct key is inserted).
- `get` on a nonexistent key → returns -1 without altering cache state.
