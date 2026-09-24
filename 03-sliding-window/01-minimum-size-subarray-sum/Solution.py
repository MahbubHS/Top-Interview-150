class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        l = 0
        total = 0
        best = float('inf')
        for r in range(len(nums)):
            total += nums[r]
            while total >= target:
                best = min(best, r - l + 1)
                total -= nums[l]
                l += 1
        return best if best != float('inf') else 0
