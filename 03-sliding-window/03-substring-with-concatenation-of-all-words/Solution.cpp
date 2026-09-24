class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) return res;
        int wordLen = words[0].size();
        int numWords = words.size();
        int totalLen = wordLen * numWords;
        int n = s.size();
        if (n < totalLen) return res;

        unordered_map<string,int> wordCount;
        for (auto& w : words) wordCount[w]++;

        for (int offset = 0; offset < wordLen; offset++) {
            int left = offset, count = 0;
            unordered_map<string,int> window;
            for (int right = offset; right + wordLen <= n; right += wordLen) {
                string word = s.substr(right, wordLen);
                if (wordCount.count(word)) {
                    window[word]++;
                    count++;
                    while (window[word] > wordCount[word]) {
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                    if (count == numWords) {
                        res.push_back(left);
                        string leftWord = s.substr(left, wordLen);
                        window[leftWord]--;
                        left += wordLen;
                        count--;
                    }
                } else {
                    window.clear();
                    count = 0;
                    left = right + wordLen;
                }
            }
        }
        return res;
    }
};
