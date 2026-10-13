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
    int postIdx = 0;

    TreeNode* build(vector<int>& postorder, int lo, int hi) {
        if (lo > hi) return nullptr;
        int val = postorder[postIdx--];
        TreeNode* node = new TreeNode(val);
        int mid = index[val];
        node->right = build(postorder, mid + 1, hi);
        node->left = build(postorder, lo, mid - 1);
        return node;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index.clear();
        postIdx = (int)postorder.size() - 1;
        for (int i = 0; i < (int)inorder.size(); i++) index[inorder[i]] = i;
        return build(postorder, 0, (int)inorder.size() - 1);
    }
};
