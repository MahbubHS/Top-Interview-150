from collections import deque

class Solution:
    def findOrder(self, numCourses: int, prerequisites: list[list[int]]) -> list[int]:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for course, pre in prerequisites:
            adj[pre].append(course)
            indeg[course] += 1
        q = deque(i for i in range(numCourses) if indeg[i] == 0)
        order = []
        while q:
            cur = q.popleft()
            order.append(cur)
            for nxt in adj[cur]:
                indeg[nxt] -= 1
                if indeg[nxt] == 0:
                    q.append(nxt)
        return order if len(order) == numCourses else []
