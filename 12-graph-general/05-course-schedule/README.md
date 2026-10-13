# Course Schedule

**Difficulty:** Medium | **Category:** Graph General
**LeetCode:** https://leetcode.com/problems/course-schedule/

## Problem Understanding
Given `numCourses` and prerequisite pairs `[course, pre]`, decide whether all courses can be finished — equivalently, whether the dependency graph has no cycle.

## Approach
**Kahn's topological sort.** Count each course's unmet prerequisites (in-degree). Repeatedly take a course with none, "complete" it, and reduce the in-degree of the courses that depend on it. If every course gets completed the graph is acyclic; if some remain stuck, they are in a cycle.

## Algorithm
1. Build `adj[pre] → course` and in-degree counts.
2. Queue all courses with in-degree 0.
3. Pop, count it, decrement dependents' in-degrees, enqueue new zeros.
4. Return whether the number processed equals `numCourses`.

## Code
- [Solution.py](./Solution.py)
- [Solution.cpp](./Solution.cpp)
- [Solution.java](./Solution.java)

## Dry Run
`2, [[1,0]]`: 0 has no prerequisite, then 1 becomes free → both processed → `True`. `[[1,0],[0,1]]`: neither ever reaches in-degree 0 → `False`.

## Complexity
- Time: O(V + E)
- Space: O(V + E)

## Edge Cases
- No prerequisites → `True`.
- A self-dependency `[a, a]` is a cycle → `False`.
