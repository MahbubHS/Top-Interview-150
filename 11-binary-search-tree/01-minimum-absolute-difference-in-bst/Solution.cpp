struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int best = INT_MAX;
    bool hasPrev = false;
    int prev = 0;

    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        if (hasPrev) best = min(best, node->val - prev);
        prev = node->val;
        hasPrev = true;
        inorder(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        best = INT_MAX;
        hasPrev = false;
        inorder(root);
        return best;
    }
};
