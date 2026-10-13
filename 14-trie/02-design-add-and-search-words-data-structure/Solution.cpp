class WordDictionary {
    struct Node {
        Node* next[26] = {nullptr};
        bool end = false;
    };
    Node* root;

    bool dfs(Node* node, const string& w, int i) {
        if (!node) return false;
        if (i == (int)w.size()) return node->end;
        if (w[i] == '.') {
            for (int k = 0; k < 26; k++) {
                if (node->next[k] && dfs(node->next[k], w, i + 1)) return true;
            }
            return false;
        }
        return dfs(node->next[w[i] - 'a'], w, i + 1);
    }
public:
    WordDictionary() { root = new Node(); }

    void addWord(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Node();
            node = node->next[ch - 'a'];
        }
        node->end = true;
    }

    bool search(string word) {
        return dfs(root, word, 0);
    }
};
