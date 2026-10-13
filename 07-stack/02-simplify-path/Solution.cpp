class Solution {
public:
    string simplifyPath(string path) {
        vector<string> stack;
        stringstream ss(path);
        string part;
        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") continue;
            else if (part == "..") {
                if (!stack.empty()) stack.pop_back();
            } else {
                stack.push_back(part);
            }
        }
        string res;
        for (auto& p : stack) res += "/" + p;
        return res.empty() ? "/" : res;
    }
};
