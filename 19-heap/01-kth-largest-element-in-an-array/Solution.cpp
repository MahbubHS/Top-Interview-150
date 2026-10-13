class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap(nums.begin(), nums.begin() + k);
        for (int i = k; i < (int)nums.size(); i++) {
            if (nums[i] > heap.top()) {
                heap.pop();
                heap.push(nums[i]);
            }
        }
        return heap.top();
    }
};
