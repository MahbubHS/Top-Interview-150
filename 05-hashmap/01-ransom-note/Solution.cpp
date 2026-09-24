class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> magCount;
        for (char c : magazine) magCount[c]++;
        for (char c : ransomNote) {
            if (--magCount[c] < 0) return false;
        }
        return true;
    }
};
