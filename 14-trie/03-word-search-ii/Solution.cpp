class Solution {
    struct Node {
        Node* next[26] = {nullptr};
        string word;
    };
    vector<string> res;
    int rows, cols;

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        char ch = board[r][c];
        Node* nxt = node->next[ch - 'a'];
        if (!nxt) return;
        if (!nxt->word.empty()) {
            res.push_back(nxt->word);
            nxt->word.clear();
        }
        board[r][c] = '#';
        int dr[4] = {1, -1, 0, 0}, dc[4] = {0, 0, 1, -1};
        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d], nc = c + dc[d];
            if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && board[nr][nc] != '#') {
                dfs(board, nr, nc, nxt);
            }
        }
        board[r][c] = ch;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root = new Node();
        for (auto& w : words) {
            Node* node = root;
            for (char ch : w) {
                if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Node();
                node = node->next[ch - 'a'];
            }
            node->word = w;
        }
        res.clear();
        rows = board.size();
        cols = board[0].size();
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) dfs(board, r, c, root);
        }
        return res;
    }
};
