import java.util.*;

class Solution {
    public int numIslands(char[][] grid) {
        int rows = grid.length, cols = grid[0].length, count = 0;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != '1') continue;
                count++;
                grid[r][c] = '0';
                Deque<int[]> stack = new ArrayDeque<>();
                stack.push(new int[]{r, c});
                while (!stack.isEmpty()) {
                    int[] cur = stack.pop();
                    for (int[] d : dirs) {
                        int nx = cur[0] + d[0], ny = cur[1] + d[1];
                        if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && grid[nx][ny] == '1') {
                            grid[nx][ny] = '0';
                            stack.push(new int[]{nx, ny});
                        }
                    }
                }
            }
        }
        return count;
    }
}
