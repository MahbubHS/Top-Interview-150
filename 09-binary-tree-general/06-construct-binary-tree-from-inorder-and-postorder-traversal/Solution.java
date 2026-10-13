import java.util.HashMap;
import java.util.Map;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}


class Solution {
    private Map<Integer, Integer> index = new HashMap<>();
    private int postIdx;

    public TreeNode buildTree(int[] inorder, int[] postorder) {
        index.clear();
        postIdx = postorder.length - 1;
        for (int i = 0; i < inorder.length; i++) index.put(inorder[i], i);
        return build(postorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] postorder, int lo, int hi) {
        if (lo > hi) return null;
        int val = postorder[postIdx--];
        TreeNode node = new TreeNode(val);
        int mid = index.get(val);
        node.right = build(postorder, mid + 1, hi);
        node.left = build(postorder, lo, mid - 1);
        return node;
    }
}
