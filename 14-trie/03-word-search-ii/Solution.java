import java.util.*;

class Solution {
    private static class Node {
        Node[] next = new Node[26];
        String word;
    }

    private List<String> res = new ArrayList<>();
    private int rows, cols;

    public List<String> findWords(char[][] board, String[] words) {
        Node root = new Node();
        for (String w : words) {
            Node node = root;
            for (char ch : w.toCharArray()) {
                if (node.next[ch - 'a'] == null) node.next[ch - 'a'] = new Node();
                node = node.next[ch - 'a'];
            }
            node.word = w;
        }
        res = new ArrayList<>();
        rows = board.length;
        cols = board[0].length;
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) dfs(board, r, c, root);
        }
        return res;
    }

    private void dfs(char[][] board, int r, int c, Node node) {
        char ch = board[r][c];
        Node nxt = node.next[ch - 'a'];
        if (nxt == null) return;
        if (nxt.word != null) {
            res.add(nxt.word);
            nxt.word = null;
        }
        board[r][c] = '#';
        int[] dr = {1, -1, 0, 0}, dc = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '#') {
                dfs(board, nr, nc, nxt);
            }
        }
        board[r][c] = ch;
    }
}
