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
    int k;
    priority_queue<int> q;
public:
    void dfs(TreeNode *node) {
        q.push(node->val);
        if (q.size() > k) q.pop();
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
    }

    int kthSmallest(TreeNode *root, int k) {
        this->k = k;
        dfs(root);
        return q.top();
    }
};