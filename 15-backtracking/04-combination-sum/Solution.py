class Solution:
    def combinationSum(self, candidates: list[int], target: int) -> list[list[int]]:
        res = []
        path = []

        def bt(start, remaining):
            if remaining == 0:
                res.append(path[:])
                return
            for i in range(start, len(candidates)):
                if candidates[i] > remaining:
                    continue
                path.append(candidates[i])
                bt(i, remaining - candidates[i])
                path.pop()

        bt(0, target)
        return res
