class Solution:
    def combine(self, n: int, k: int) -> list[list[int]]:
        res = []
        path = []

        def bt(start):
            if len(path) == k:
                res.append(path[:])
                return
            for i in range(start, n - (k - len(path)) + 2):
                path.append(i)
                bt(i + 1)
                path.pop()

        bt(1)
        return res
