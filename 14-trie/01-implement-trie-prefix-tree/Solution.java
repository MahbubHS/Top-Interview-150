class Trie {
    private static class Node {
        Node[] next = new Node[26];
        boolean end;
    }

    private final Node root = new Node();

    public Trie() {}

    public void insert(String word) {
        Node node = root;
        for (char ch : word.toCharArray()) {
            if (node.next[ch - 'a'] == null) node.next[ch - 'a'] = new Node();
            node = node.next[ch - 'a'];
        }
        node.end = true;
    }

    private Node find(String s) {
        Node node = root;
        for (char ch : s.toCharArray()) {
            node = node.next[ch - 'a'];
            if (node == null) return null;
        }
        return node;
    }

    public boolean search(String word) {
        Node node = find(word);
        return node != null && node.end;
    }

    public boolean startsWith(String prefix) {
        return find(prefix) != null;
    }
}
