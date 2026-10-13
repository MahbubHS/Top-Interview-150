class Solution {
    vector<vector<int>> res;
    vector<int> path;

    void bt(vector<int>& candidates, int start, int remaining) {
        if (remaining == 0) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < (int)candidates.size(); i++) {
            if (candidates[i] > remaining) continue;
            path.push_back(candidates[i]);
            bt(candidates, i, remaining - candidates[i]);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        res.clear();
        path.clear();
        bt(candidates, 0, target);
        return res;
    }
};
