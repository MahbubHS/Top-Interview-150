class Solution:
    def maxSubArray(self, nums: list[int]) -> int:
        best = nums[0]
        cur = nums[0]
        for num in nums[1:]:
            cur = max(num, cur + num)
            best = max(best, cur)
        return best
