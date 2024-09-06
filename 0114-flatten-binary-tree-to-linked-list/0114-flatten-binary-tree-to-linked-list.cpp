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
    vector<int> nums;
    TreeNode* preorder(TreeNode* root){
        if (root == nullptr)
            return nullptr;
        nums.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
        return root;
    }
    void flatten(TreeNode* root) {
        preorder(root);
        for(int i = 1; i < nums.size(); i++){
            TreeNode* val = new TreeNode(nums[i]);
            root->right = val; 
            root->left = nullptr;
            root = root->right;
        }
    }
    

};