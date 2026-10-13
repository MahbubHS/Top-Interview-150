class Solution {
    vector<string> res;
    string path;

    void bt(int open, int close, int n) {
        if ((int)path.size() == 2 * n) {
            res.push_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            bt(open + 1, close, n);
            path.pop_back();
        }
        if (close < open) {
            path.push_back(')');
            bt(open, close + 1, n);
            path.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        res.clear();
        path.clear();
        bt(0, 0, n);
        return res;
    }
};
