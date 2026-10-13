class Solution:
    def permute(self, nums: list[int]) -> list[list[int]]:
        res = []
        path = []
        used = [False] * len(nums)

        def bt():
            if len(path) == len(nums):
                res.append(path[:])
                return
            for i, x in enumerate(nums):
                if used[i]:
                    continue
                used[i] = True
                path.append(x)
                bt()
                path.pop()
                used[i] = False

        bt()
        return res
