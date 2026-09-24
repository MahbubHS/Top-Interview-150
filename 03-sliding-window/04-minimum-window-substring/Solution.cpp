class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char,int> need;
        for (char c : t) need[c]++;
        int missing = t.size();
        int l = 0, bestL = 0, bestR = 0;
        for (int r = 1; r <= (int)s.size(); r++) {
            char c = s[r - 1];
            if (need[c] > 0) missing--;
            need[c]--;
            if (missing == 0) {
                while (l < r && need[s[l]] < 0) {
                    need[s[l]]++;
                    l++;
                }
                if (bestR == 0 || r - l < bestR - bestL) {
                    bestL = l; bestR = r;
                }
                need[s[l]]++;
                missing++;
                l++;
            }
        }
        return s.substr(bestL, bestR - bestL);
    }
};
