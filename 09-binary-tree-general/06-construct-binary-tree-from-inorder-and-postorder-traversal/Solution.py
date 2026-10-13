# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def buildTree(self, inorder: list[int], postorder: list[int]) -> 'TreeNode':
        index = {val: i for i, val in enumerate(inorder)}
        post_idx = len(postorder) - 1

        def build(lo: int, hi: int) -> 'TreeNode':
            nonlocal post_idx
            if lo > hi:
                return None
            val = postorder[post_idx]
            post_idx -= 1
            node = TreeNode(val)
            mid = index[val]
            node.right = build(mid + 1, hi)
            node.left = build(lo, mid - 1)
            return node

        return build(0, len(inorder) - 1)
