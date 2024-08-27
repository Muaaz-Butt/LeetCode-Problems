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
    pair<int, bool> helper(TreeNode* root){
        if (root == nullptr){
            return {0, true};
        }
        auto left = helper(root->left);
        auto right = helper(root->right);
        int height = max(left.first, right.first) + 1;
        bool is_balanced = left.second && right.second &&  abs(left.first - right.first) <= 1; 
        return {height, is_balanced};

    }
    bool isBalanced(TreeNode* root) {
       return helper(root).second;
    }
};