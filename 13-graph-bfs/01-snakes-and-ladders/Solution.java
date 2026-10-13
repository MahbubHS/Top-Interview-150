import java.util.*;

class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.length, target = n * n;
        int[] dist = new int[target + 1];
        Arrays.fill(dist, -1);
        Deque<Integer> q = new ArrayDeque<>();
        dist[1] = 0;
        q.add(1);
        while (!q.isEmpty()) {
            int cur = q.poll();
            if (cur == target) return dist[cur];
            for (int nxt = cur + 1; nxt <= Math.min(cur + 6, target); nxt++) {
                int r = (nxt - 1) / n, c = (nxt - 1) % n;
                if (r % 2 == 1) c = n - 1 - c;
                int dest = board[n - 1 - r][c];
                int to = dest != -1 ? dest : nxt;
                if (dist[to] == -1) {
                    dist[to] = dist[cur] + 1;
                    q.add(to);
                }
            }
        }
        return -1;
    }
}
