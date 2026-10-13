from collections import deque

class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        adj = [[] for _ in range(numCourses)]
        indeg = [0] * numCourses
        for course, pre in prerequisites:
            adj[pre].append(course)
            indeg[course] += 1
        q = deque(i for i in range(numCourses) if indeg[i] == 0)
        taken = 0
        while q:
            cur = q.popleft()
            taken += 1
            for nxt in adj[cur]:
                indeg[nxt] -= 1
                if indeg[nxt] == 0:
                    q.append(nxt)
        return taken == numCourses
