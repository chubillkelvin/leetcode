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
    int cameras = 0;
    unordered_map<TreeNode *, TreeNode *> parent;
    unordered_map<TreeNode *, bool> covered;
public:
    bool isCovered(TreeNode *root) {
        if (!root) return true;
        return covered[root];
    }

    void putCamera(TreeNode *root) {
        if (!root) return;
        cameras++;
        covered[root] = true;
        if (parent[root]) covered[parent[root]] = true;
        if (root->left) covered[root->left] = true;
        if (root->right) covered[root->right] = true;
    }

    void dfs(TreeNode *root) {
        if (!root) return;
        if (root->left) parent[root->left] = root;
        if (root->right) parent[root->right] = root;
        dfs(root->left);
        dfs(root->right);
        if (!isCovered(root->left) || !isCovered(root->right) || !parent[root] && !isCovered(root)) putCamera(root);
    }

    int minCameraCover(TreeNode *root) {
        dfs(root);
        return cameras;
    }
};