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
    int getMaxDiff(TreeNode *root, int currMin, int currMax) {
        if (!root) return currMax - currMin;
        int curr = root->val;
        currMin = min(curr, currMin);
        currMax = max(curr, currMax);
        int leftDiff = getMaxDiff(root->left, currMin, currMax);
        int rightDiff = getMaxDiff(root->right, currMin, currMax);
        return max(leftDiff, rightDiff);
    }

    int maxAncestorDiff(TreeNode *root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 0;
        int curr = root->val;
        return getMaxDiff(root, curr, curr);
    }
};