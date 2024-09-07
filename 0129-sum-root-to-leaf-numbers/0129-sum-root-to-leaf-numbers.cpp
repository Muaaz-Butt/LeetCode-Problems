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
    int helper(TreeNode* root, int num){
        if (!root){
            return 0;
        }
        if (!root->left && !root->right){
            num = num * 10 + root->val;
            cout << num << endl;
            return num;
        }
        num = num * 10 + root->val;
        int left_path = helper(root->left, num);
        int right_path = helper(root->right, num);

        return left_path + right_path;
    }
    int sumNumbers(TreeNode* root) {
        int num = 0, result = 0;
        return helper(root, num);
    }
};