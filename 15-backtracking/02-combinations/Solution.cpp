class Solution {
    vector<vector<int>> res;
    vector<int> path;

    void bt(int start, int n, int k) {
        if ((int)path.size() == k) {
            res.push_back(path);
            return;
        }
        for (int i = start; i <= n - (k - (int)path.size()) + 1; i++) {
            path.push_back(i);
            bt(i + 1, n, k);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        res.clear();
        path.clear();
        bt(1, n, k);
        return res;
    }
};
