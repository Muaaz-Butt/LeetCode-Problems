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
    bool helper(TreeNode* root, int& sum, int targetSum){
        if (root == nullptr){
            return false;
        }
        sum += root->val;
        cout << "sum up: " <<sum<<"\n";
        
        if (root->left == nullptr && root->right == nullptr && sum == targetSum){
            return true;  
        }

        if (helper(root->left, sum, targetSum) || helper(root->right, sum, targetSum)){
            return true;
        }
        
        sum -= root->val;
        cout << "sum down :" <<sum << endl;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        return helper(root, sum, targetSum);
    }
};