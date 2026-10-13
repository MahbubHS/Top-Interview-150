# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def countNodes(self, root: 'TreeNode') -> int:
        if not root:
            return 0
        left_h = right_h = 0
        l = r = root
        while l:
            left_h += 1
            l = l.left
        while r:
            right_h += 1
            r = r.right
        if left_h == right_h:
            return (1 << left_h) - 1
        return 1 + self.countNodes(root.left) + self.countNodes(root.right)
