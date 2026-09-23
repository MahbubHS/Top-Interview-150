class Solution {
public:
    string reverseWords(string s) {
        istringstream iss(s);
        vector<string> words;
        string w;
        while (iss >> w) words.push_back(w);
        reverse(words.begin(), words.end());
        string res;
        for (int i = 0; i < (int)words.size(); i++) {
            res += words[i];
            if (i != (int)words.size() - 1) res += " ";
        }
        return res;
    }
};
