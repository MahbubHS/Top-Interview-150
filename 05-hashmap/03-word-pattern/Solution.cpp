class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        istringstream iss(s);
        string w;
        while (iss >> w) words.push_back(w);
        if (pattern.size() != words.size()) return false;

        unordered_map<char,string> mapPW;
        unordered_map<string,char> mapWP;
        for (int i = 0; i < (int)pattern.size(); i++) {
            char ch = pattern[i];
            string word = words[i];
            if (mapPW.count(ch) && mapPW[ch] != word) return false;
            if (mapWP.count(word) && mapWP[word] != ch) return false;
            mapPW[ch] = word;
            mapWP[word] = ch;
        }
        return true;
    }
};
