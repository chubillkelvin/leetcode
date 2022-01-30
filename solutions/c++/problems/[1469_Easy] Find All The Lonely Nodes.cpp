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
    vector<int> lonely;
public:
    void dfs(TreeNode *node) {
        if (node->left && node->right) {
            dfs(node->left);
            dfs(node->right);
        } else if (node->left) {
            dfs(node->left);
            lonely.push_back(node->left->val);
        } else if (node->right) {
            dfs(node->right);
            lonely.push_back(node->right->val);
        }
    }

    vector<int> getLonelyNodes(TreeNode *root) {
        dfs(root);
        return lonely;
    }
};