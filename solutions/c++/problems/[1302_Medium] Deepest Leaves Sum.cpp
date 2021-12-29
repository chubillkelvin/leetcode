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
    int deepestLevel = 1;
    vector<TreeNode *> leaves;
public:
    void dfs(TreeNode *node, int level) {
        if (!node->left && !node->right) {
            if (level == deepestLevel) {
                leaves.push_back(node);
            } else if (level > deepestLevel) {
                deepestLevel = level;
                leaves = {node};
            }
            return;
        }
        if (node->left) dfs(node->left, level + 1);
        if (node->right) dfs(node->right, level + 1);
    }

    int deepestLeavesSum(TreeNode *root) {
        dfs(root, 1);
        int sum = 0;
        for (auto leaf: leaves) sum += leaf->val;
        return sum;
    }
};