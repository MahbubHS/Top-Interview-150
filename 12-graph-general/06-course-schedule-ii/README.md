# Course Schedule II

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/course-schedule-ii/

## Problem Understanding
Return a valid order to take all courses given prerequisite pairs, or an empty list if it is impossible (a cycle exists).

## Approach
Same Kahn topological sort as Course Schedule, but record the order in which courses are removed from the queue. If fewer than `numCourses` courses get processed, a cycle blocks completion and the answer is empty.

## Algorithm
1. Build adjacency and in-degrees.
2. Process the queue of zero in-degree courses, appending each popped course to `order`.
3. Return `order` if it has all courses, else `[]`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`4, [[1,0],[2,0],[3,1],[3,2]]`: 0 first, then 1 and 2, then 3 → e.g. `[0,1,2,3]` (any valid order is accepted).

## Complexity
- Time: O(V + E)
- Space: O(V + E)

## Edge Cases
- Cycle → `[]`.
- Multiple valid orders exist; any one is accepted.
