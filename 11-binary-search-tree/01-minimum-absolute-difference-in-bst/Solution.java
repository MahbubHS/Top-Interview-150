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
    private int best;
    private Integer prev;

    public int getMinimumDifference(TreeNode root) {
        best = Integer.MAX_VALUE;
        prev = null;
        inorder(root);
        return best;
    }

    private void inorder(TreeNode node) {
        if (node == null) return;
        inorder(node.left);
        if (prev != null) best = Math.min(best, node.val - prev);
        prev = node.val;
        inorder(node.right);
    }
}
