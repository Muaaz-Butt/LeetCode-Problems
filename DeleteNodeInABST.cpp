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
    int minValue(TreeNode* root) {
        int min = root->val;
        while (root != nullptr) {
            min = root->val;
            root = root->left;
        }
        return min;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr)
            return nullptr;
        if (key > root->val)
            root->right = deleteNode(root->right, key);
        else if (key < root->val)
            root->left = deleteNode(root->left, key);
        else
        {
            if (root->left == nullptr && root->right == nullptr) {
                delete root;
                return nullptr;
            }
            else if (root->left == nullptr || root->right == nullptr) {
                TreeNode* temp = root->left ? root->left : root->right;
                delete root;
                return temp;
            }
            else {
                root->val = minValue(root->right);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
};