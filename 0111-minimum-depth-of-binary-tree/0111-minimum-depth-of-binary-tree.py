# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root: Optional[TreeNode]) -> int:
        if root is None:
            return 0
        if root.left is None and root.right is None:
            return 1
        if root.left is None:
            return 1 + self.helper(root.right)
        if root.right is None:
            return 1 + self.helper(root.left)
        return 1 + min(self.helper(root.left), self.helper(root.right))
    def minDepth(self, root: Optional[TreeNode]) -> int:
        return self.helper(root)
        