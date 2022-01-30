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
    bool isLeaf(TreeNode *root) {
        if (!root->left && !root->right) return true;
        return false;
    }

    TreeNode *removeLeafNodes(TreeNode *root, int target) {
        if (root->left) {
            removeLeafNodes(root->left, target);
            if (root->left->val == target && isLeaf(root->left)) {
                root->left = nullptr;
            }
        }
        if (root->right) {
            removeLeafNodes(root->right, target);
            if (root->right->val == target && isLeaf(root->right)) {
                root->right = nullptr;
            }
        }
        return isLeaf(root) && root->val == target ? nullptr : root;
    }
};