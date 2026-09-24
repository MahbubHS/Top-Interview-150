class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int l = 0, total = 0, best = Integer.MAX_VALUE;
        for (int r = 0; r < nums.length; r++) {
            total += nums[r];
            while (total >= target) {
                best = Math.min(best, r - l + 1);
                total -= nums[l];
                l++;
            }
        }
        return best == Integer.MAX_VALUE ? 0 : best;
    }
}
