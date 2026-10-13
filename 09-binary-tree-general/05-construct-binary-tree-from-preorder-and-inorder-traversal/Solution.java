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
    private int preIdx = 0;

    public TreeNode buildTree(int[] preorder, int[] inorder) {
        index.clear();
        preIdx = 0;
        for (int i = 0; i < inorder.length; i++) index.put(inorder[i], i);
        return build(preorder, 0, inorder.length - 1);
    }

    private TreeNode build(int[] preorder, int lo, int hi) {
        if (lo > hi) return null;
        int val = preorder[preIdx++];
        TreeNode node = new TreeNode(val);
        int mid = index.get(val);
        node.left = build(preorder, lo, mid - 1);
        node.right = build(preorder, mid + 1, hi);
        return node;
    }
}
