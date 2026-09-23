class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int idx = 0, n = words.size();
        while (idx < n) {
            int total = words[idx].size(), last = idx + 1;
            while (last < n && total + (int)words[last].size() + (last - idx) <= maxWidth) {
                total += words[last].size();
                last++;
            }
            int numWords = last - idx;
            string line;
            if (last == n || numWords == 1) {
                for (int i = idx; i < last; i++) {
                    line += words[i];
                    if (i != last - 1) line += " ";
                }
                while ((int)line.size() < maxWidth) line += " ";
            } else {
                int totalSpaces = maxWidth - total;
                int gaps = numWords - 1;
                int spaceEach = totalSpaces / gaps;
                int extra = totalSpaces % gaps;
                for (int i = idx; i < last - 1; i++) {
                    line += words[i];
                    int spaces = spaceEach + ((i - idx) < extra ? 1 : 0);
                    line += string(spaces, ' ');
                }
                line += words[last - 1];
            }
            res.push_back(line);
            idx = last;
        }
        return res;
    }
};
