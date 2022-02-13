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
    bool isValid(TreeNode *root, vector<int> &minMax) {
        if (root->left) {
            vector<int> minMaxLeft(2, 0);
            minMaxLeft[0] = INT_MAX;
            minMaxLeft[1] = INT_MIN;
            if (!isValid(root->left, minMaxLeft)) return false;
            if (minMaxLeft[1] >= root->val) return false;
            minMax[0] = min(minMax[0], minMaxLeft[0]);
            minMax[1] = max(minMax[1], minMaxLeft[1]);
        }
        if (root->right) {
            vector<int> minMaxRight(2, 0);
            minMaxRight[0] = INT_MAX;
            minMaxRight[1] = INT_MIN;
            if (!isValid(root->right, minMaxRight)) return false;
            if (minMaxRight[0] <= root->val) return false;
            minMax[0] = min(minMax[0], minMaxRight[0]);
            minMax[1] = max(minMax[1], minMaxRight[1]);
        }
        minMax[0] = min(minMax[0], root->val);
        minMax[1] = max(minMax[1], root->val);
        return true;
    }

    bool isValidBST(TreeNode *root) {
        vector<int> minMax(2);
        return isValid(root, minMax);
    }
};