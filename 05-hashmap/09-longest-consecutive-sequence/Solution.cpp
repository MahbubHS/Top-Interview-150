class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int best = 0;
        for (int num : numSet) {
            if (!numSet.count(num - 1)) {
                int length = 1;
                while (numSet.count(num + length)) length++;
                best = max(best, length);
            }
        }
        return best;
    }
};
