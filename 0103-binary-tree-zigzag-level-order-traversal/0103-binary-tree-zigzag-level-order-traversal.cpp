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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;

        while (!q.empty()) {
            int level_size = q.size();
            vector<int> temp;

            for (int i = 0; i < level_size; i++) {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            if (flag) {
                reverse(temp.begin(), temp.end());
            }

            result.push_back(temp);
            flag = !flag;
        }

        return result;
    }
};
