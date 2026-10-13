class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
        vector<int> order;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            order.push_back(cur);
            for (int nxt : adj[cur]) {
                if (--indeg[nxt] == 0) q.push(nxt);
            }
        }
        if ((int)order.size() != numCourses) return {};
        return order;
    }
};
