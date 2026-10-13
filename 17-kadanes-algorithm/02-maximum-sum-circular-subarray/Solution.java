class Solution {
    public int maxSubarraySumCircular(int[] nums) {
        int total = 0, curMax = 0, bestMax = nums[0], curMin = 0, bestMin = nums[0];
        for (int num : nums) {
            curMax = Math.max(num, curMax + num);
            bestMax = Math.max(bestMax, curMax);
            curMin = Math.min(num, curMin + num);
            bestMin = Math.min(bestMin, curMin);
            total += num;
        }
        if (bestMax < 0) return bestMax;
        return Math.max(bestMax, total - bestMin);
    }
}
