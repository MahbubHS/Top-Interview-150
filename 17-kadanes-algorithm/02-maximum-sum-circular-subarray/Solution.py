class Solution:
    def maxSubarraySumCircular(self, nums: list[int]) -> int:
        total = 0
        cur_max = 0
        best_max = nums[0]
        cur_min = 0
        best_min = nums[0]
        for num in nums:
            cur_max = max(num, cur_max + num)
            best_max = max(best_max, cur_max)
            cur_min = min(num, cur_min + num)
            best_min = min(best_min, cur_min)
            total += num
        if best_max < 0:
            return best_max
        return max(best_max, total - best_min)
