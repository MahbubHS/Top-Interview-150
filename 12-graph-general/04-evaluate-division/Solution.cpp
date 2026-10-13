class Solution {
    unordered_map<string, unordered_map<string, double>> graph;

    double dfs(const string& src, const string& dst, unordered_set<string>& visited) {
        if (!graph.count(src) || !graph.count(dst)) return -1.0;
        if (src == dst) return 1.0;
        visited.insert(src);
        for (auto& [nb, w] : graph[src]) {
            if (visited.count(nb)) continue;
            double r = dfs(nb, dst, visited);
            if (r != -1.0) return w * r;
        }
        return -1.0;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
                                vector<vector<string>>& queries) {
        graph.clear();
        for (int i = 0; i < (int)equations.size(); i++) {
            graph[equations[i][0]][equations[i][1]] = values[i];
            graph[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }
        vector<double> res;
        for (auto& q : queries) {
            unordered_set<string> visited;
            res.push_back(dfs(q[0], q[1], visited));
        }
        return res;
    }
};
