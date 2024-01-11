/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* helper(TreeNode* cloned, int target) {
        if (cloned == nullptr) {
            return nullptr;
        }
        if (cloned->val == target) {
            return cloned;
        }
        TreeNode* reference = helper(cloned->left, target);
        if (reference) {
            return reference;
        }
        reference = helper(cloned->right, target);
        if (reference)
            return reference;
        return nullptr;
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if (cloned == nullptr) {
            return nullptr;
        }
        return helper(cloned, target->val);
    }
};