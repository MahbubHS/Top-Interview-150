struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    unordered_map<int,int> index;
    int preIdx = 0;

    TreeNode* build(vector<int>& preorder, int lo, int hi) {
        if (lo > hi) return nullptr;
        int val = preorder[preIdx++];
        TreeNode* node = new TreeNode(val);
        int mid = index[val];
        node->left = build(preorder, lo, mid - 1);
        node->right = build(preorder, mid + 1, hi);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        index.clear();
        preIdx = 0;
        for (int i = 0; i < (int)inorder.size(); i++) index[inorder[i]] = i;
        return build(preorder, 0, (int)inorder.size() - 1);
    }
};
