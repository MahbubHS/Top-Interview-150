class Trie {
    struct Node {
        Node* next[26] = {nullptr};
        bool end = false;
    };
    Node* root;

    Node* find(const string& s) {
        Node* node = root;
        for (char ch : s) {
            node = node->next[ch - 'a'];
            if (!node) return nullptr;
        }
        return node;
    }
public:
    Trie() { root = new Node(); }

    void insert(string word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->next[ch - 'a']) node->next[ch - 'a'] = new Node();
            node = node->next[ch - 'a'];
        }
        node->end = true;
    }

    bool search(string word) {
        Node* node = find(word);
        return node && node->end;
    }

    bool startsWith(string prefix) {
        return find(prefix) != nullptr;
    }
};
