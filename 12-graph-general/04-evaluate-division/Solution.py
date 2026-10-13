from collections import defaultdict

class Solution:
    def calcEquation(self, equations: list[list[str]], values: list[float],
                     queries: list[list[str]]) -> list[float]:
        graph = defaultdict(dict)
        for (a, b), v in zip(equations, values):
            graph[a][b] = v
            graph[b][a] = 1.0 / v

        def dfs(src, dst, visited):
            if src not in graph or dst not in graph:
                return -1.0
            if src == dst:
                return 1.0
            visited.add(src)
            for nb, w in graph[src].items():
                if nb in visited:
                    continue
                r = dfs(nb, dst, visited)
                if r != -1.0:
                    return w * r
            return -1.0

        return [dfs(a, b, set()) for a, b in queries]
