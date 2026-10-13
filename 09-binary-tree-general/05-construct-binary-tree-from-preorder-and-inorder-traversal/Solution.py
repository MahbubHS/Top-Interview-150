# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, preorder: list[int], inorder: list[int]) -> 'TreeNode':
        index = {val: i for i, val in enumerate(inorder)}
        pre_idx = 0

        def build(lo: int, hi: int) -> 'TreeNode':
            nonlocal pre_idx
            if lo > hi:
                return None
            val = preorder[pre_idx]
            pre_idx += 1
            node = TreeNode(val)
            mid = index[val]
            node.left = build(lo, mid - 1)
            node.right = build(mid + 1, hi)
            return node

        return build(0, len(inorder) - 1)
