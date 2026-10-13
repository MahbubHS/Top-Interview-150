import java.util.*;

class Solution {
    public void solve(char[][] board) {
        int rows = board.length, cols = board[0].length;
        int[][] dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        Deque<int[]> stack = new ArrayDeque<>();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                boolean border = (r == 0 || r == rows - 1 || c == 0 || c == cols - 1);
                if (border && board[r][c] == 'O') {
                    board[r][c] = 'T';
                    stack.push(new int[]{r, c});
                }
            }
        }
        while (!stack.isEmpty()) {
            int[] cur = stack.pop();
            for (int[] d : dirs) {
                int nx = cur[0] + d[0], ny = cur[1] + d[1];
                if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && board[nx][ny] == 'O') {
                    board[nx][ny] = 'T';
                    stack.push(new int[]{nx, ny});
                }
            }
        }
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (board[r][c] == 'O') board[r][c] = 'X';
                else if (board[r][c] == 'T') board[r][c] = 'O';
            }
        }
    }
}
