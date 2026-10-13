class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indeg(numCourses, 0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        for (int i = 0; i < numCourses; i++) if (indeg[i] == 0) q.push(i);
        int taken = 0;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            taken++;
            for (int nxt : adj[cur]) {
                if (--indeg[nxt] == 0) q.push(nxt);
            }
        }
        return taken == numCourses;
    }
};
