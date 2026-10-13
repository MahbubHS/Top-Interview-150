from collections import deque

class Solution:
    def snakesAndLadders(self, board: list[list[int]]) -> int:
        n = len(board)

        def cell(s):
            r, c = divmod(s - 1, n)
            if r % 2 == 1:
                c = n - 1 - c
            return board[n - 1 - r][c]

        dist = {1: 0}
        q = deque([1])
        while q:
            cur = q.popleft()
            if cur == n * n:
                return dist[cur]
            for nxt in range(cur + 1, min(cur + 6, n * n) + 1):
                dest = cell(nxt)
                to = dest if dest != -1 else nxt
                if to not in dist:
                    dist[to] = dist[cur] + 1
                    q.append(to)
        return -1
