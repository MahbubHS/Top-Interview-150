# Clone Graph

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/clone-graph/

## Problem Understanding
Deep-copy a connected undirected graph given one of its nodes; the copy must use brand-new node objects with the same connections.

## Approach
Keep a map from each original node to its clone. When a neighbor has no clone yet, create it and schedule it for visiting; either way, link the current clone to the neighbor's clone. The map also prevents infinite loops on cycles.

## Algorithm
1. Create a clone of the start node and put it in the map; push the start on a stack.
2. Pop `cur`. For each neighbor: create + record a clone if missing (and push it), then append the neighbor's clone to `clones[cur].neighbors`.
3. Return the clone of the start node.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
Square graph 1-2-3-4-1: cloning visits each node once, creating 4 clones and wiring each clone to the clones of its two neighbors.

## Complexity
- Time: O(V + E)
- Space: O(V)

## Edge Cases
- `null` input → `null`.
- Single node with no neighbors → single cloned node.
