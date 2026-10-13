import java.util.*;

class Node {
    public int val;
    public List<Node> neighbors;
    public Node() { val = 0; neighbors = new ArrayList<Node>(); }
    public Node(int _val) { val = _val; neighbors = new ArrayList<Node>(); }
    public Node(int _val, ArrayList<Node> _neighbors) { val = _val; neighbors = _neighbors; }
}

class Solution {
    public Node cloneGraph(Node node) {
        if (node == null) return null;
        Map<Node, Node> clones = new HashMap<>();
        clones.put(node, new Node(node.val));
        Deque<Node> stack = new ArrayDeque<>();
        stack.push(node);
        while (!stack.isEmpty()) {
            Node cur = stack.pop();
            for (Node nb : cur.neighbors) {
                if (!clones.containsKey(nb)) {
                    clones.put(nb, new Node(nb.val));
                    stack.push(nb);
                }
                clones.get(cur).neighbors.add(clones.get(nb));
            }
        }
        return clones.get(node);
    }
}
