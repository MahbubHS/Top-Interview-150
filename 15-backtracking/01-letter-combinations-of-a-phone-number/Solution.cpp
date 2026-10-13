class Solution {
    vector<string> res;
    string path;
    const vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void bt(const string& digits, int i) {
        if (i == (int)digits.size()) {
            res.push_back(path);
            return;
        }
        for (char ch : mp[digits[i] - '0']) {
            path.push_back(ch);
            bt(digits, i + 1);
            path.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        res.clear();
        path.clear();
        if (digits.empty()) return res;
        bt(digits, 0);
        return res;
    }
};
