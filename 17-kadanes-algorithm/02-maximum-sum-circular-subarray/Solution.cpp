class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total = 0, curMax = 0, bestMax = nums[0], curMin = 0, bestMin = nums[0];
        for (int num : nums) {
            curMax = max(num, curMax + num);
            bestMax = max(bestMax, curMax);
            curMin = min(num, curMin + num);
            bestMin = min(bestMin, curMin);
            total += num;
        }
        if (bestMax < 0) return bestMax;
        return max(bestMax, total - bestMin);
    }
};
