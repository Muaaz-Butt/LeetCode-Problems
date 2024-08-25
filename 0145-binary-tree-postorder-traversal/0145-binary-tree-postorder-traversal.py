# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def __init__(self):
        self.num = []
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if root is None:
            return self.num
        self.postorderTraversal(root.left)
        self.postorderTraversal(root.right)
        self.num.append(root.val)
        return self.num