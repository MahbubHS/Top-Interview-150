class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size(), target = n * n;
        auto cell = [&](int s) {
            int r = (s - 1) / n, c = (s - 1) % n;
            if (r % 2 == 1) c = n - 1 - c;
            return board[n - 1 - r][c];
        };
        vector<int> dist(target + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            if (cur == target) return dist[cur];
            for (int nxt = cur + 1; nxt <= min(cur + 6, target); nxt++) {
                int dest = cell(nxt);
                int to = dest != -1 ? dest : nxt;
                if (dist[to] == -1) {
                    dist[to] = dist[cur] + 1;
                    q.push(to);
                }
            }
        }
        return -1;
    }
};
