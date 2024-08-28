# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def helper(self, root, current_sum, target_sum):
        if root is None:
            return False
        
        current_sum += root.val
        
        if root.left is None and root.right is None and current_sum == target_sum:
            return True
        
        if self.helper(root.left, current_sum, target_sum) or self.helper(root.right, current_sum, target_sum):
            return True
        
        current_sum -= root.val
        
        return False
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        return self.helper(root, 0, targetSum)