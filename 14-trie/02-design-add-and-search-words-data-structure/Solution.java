class WordDictionary {
    private static class Node {
        Node[] next = new Node[26];
        boolean end;
    }

    private final Node root = new Node();

    public WordDictionary() {}

    public void addWord(String word) {
        Node node = root;
        for (char ch : word.toCharArray()) {
            if (node.next[ch - 'a'] == null) node.next[ch - 'a'] = new Node();
            node = node.next[ch - 'a'];
        }
        node.end = true;
    }

    public boolean search(String word) {
        return dfs(root, word, 0);
    }

    private boolean dfs(Node node, String w, int i) {
        if (node == null) return false;
        if (i == w.length()) return node.end;
        char ch = w.charAt(i);
        if (ch == '.') {
            for (Node child : node.next) {
                if (child != null && dfs(child, w, i + 1)) return true;
            }
            return false;
        }
        return dfs(node.next[ch - 'a'], w, i + 1);
    }
}
