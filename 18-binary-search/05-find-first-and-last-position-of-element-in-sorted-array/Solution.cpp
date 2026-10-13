class Solution {
    int lowerBound(vector<int>& nums, int x) {
        int lo = 0, hi = nums.size();
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] < x) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start = lowerBound(nums, target);
        if (start == (int)nums.size() || nums[start] != target) return {-1, -1};
        int end = lowerBound(nums, target + 1) - 1;
        return {start, end};
    }
};
