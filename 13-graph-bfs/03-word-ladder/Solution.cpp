class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());
        if (!words.count(endWord)) return 0;
        queue<pair<string,int>> q;
        unordered_set<string> seen = {beginWord};
        q.push({beginWord, 1});
        while (!q.empty()) {
            auto [word, dist] = q.front();
            q.pop();
            if (word == endWord) return dist;
            for (int i = 0; i < (int)word.size(); i++) {
                char orig = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    if (ch == orig) continue;
                    word[i] = ch;
                    if (words.count(word) && !seen.count(word)) {
                        seen.insert(word);
                        q.push({word, dist + 1});
                    }
                }
                word[i] = orig;
            }
        }
        return 0;
    }
};
