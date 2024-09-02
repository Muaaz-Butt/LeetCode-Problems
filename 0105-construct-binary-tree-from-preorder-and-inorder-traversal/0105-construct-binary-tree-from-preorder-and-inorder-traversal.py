# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if len(preorder) == 1:
            root = TreeNode(preorder[0])
            return root
        inorder_map = {val: idx for idx, val in enumerate(inorder)}

        def build_tree_helper(pre_start, pre_end, in_start, in_end):
            if pre_start > pre_end or in_start > in_end:
                return None
            
            root_val = preorder[pre_start]
            root = TreeNode(root_val)

            root_idx = inorder_map[root_val]
            left_subtree = root_idx - in_start

            root.left = build_tree_helper(pre_start + 1, left_subtree + pre_start, in_start, root_idx - 1)
            root.right = build_tree_helper(pre_start + left_subtree + 1, pre_end, root_idx + 1, in_end)

            return root
        
        return build_tree_helper(0, len(preorder) - 1, 0, len(inorder) - 1)
            
