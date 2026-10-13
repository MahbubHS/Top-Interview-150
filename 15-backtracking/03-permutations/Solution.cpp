class Solution {
    vector<vector<int>> res;
    vector<int> path;
    vector<bool> used;

    void bt(vector<int>& nums) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < (int)nums.size(); i++) {
            if (used[i]) continue;
            used[i] = true;
            path.push_back(nums[i]);
            bt(nums);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        used.assign(nums.size(), false);
        bt(nums);
        return res;
    }
};
