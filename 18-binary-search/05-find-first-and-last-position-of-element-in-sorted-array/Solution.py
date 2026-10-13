class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        def lower_bound(x):
            lo, hi = 0, len(nums)
            while lo < hi:
                mid = (lo + hi) // 2
                if nums[mid] < x:
                    lo = mid + 1
                else:
                    hi = mid
            return lo

        start = lower_bound(target)
        if start == len(nums) or nums[start] != target:
            return [-1, -1]
        end = lower_bound(target + 1) - 1
        return [start, end]
