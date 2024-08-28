/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root){
        if (root == nullptr){
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr){
            return 1;
        }
        if (root->left == nullptr){
            return 1 + helper(root->right);
        }
        if (root->right == nullptr){
            return 1 + helper(root->left);
        }
        return 1 + min(helper(root->left), helper(root->right));
    }
    int minDepth(TreeNode* root) {
        return helper(root);
    }
};