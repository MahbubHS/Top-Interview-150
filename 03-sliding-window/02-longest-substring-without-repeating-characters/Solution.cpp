class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> lastSeen;
        int l = 0, best = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            char c = s[r];
            if (lastSeen.count(c) && lastSeen[c] >= l) {
                l = lastSeen[c] + 1;
            }
            lastSeen[c] = r;
            best = max(best, r - l + 1);
        }
        return best;
    }
};
