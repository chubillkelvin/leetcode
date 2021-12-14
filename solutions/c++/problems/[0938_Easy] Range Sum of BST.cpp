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
    map<TreeNode *, int> memo;

    bool isInRange(int val, int low, int high) {
        return low <= val && high >= val;
    }

    int getSum(TreeNode *root, int low, int high) {
        if (!root) return 0;
        if (memo[root]) return memo[root];

        int sum = 0;
        if (isInRange(root->val, low, high)) {
            sum += root->val;
        }
        if (root->val == low) {
            // skip left tree
            sum += getSum(root->right, low, high);
            memo[root] = sum;
            return sum;
        }
        if (root->val == high) {
            // skip right tree
            sum += getSum(root->left, low, high);
            memo[root] = sum;
            return sum;
        }
        sum = sum + getSum(root->left, low, high) + getSum(root->right, low, high);
        memo[root] = sum;
        return sum;
    }

    int rangeSumBST(TreeNode *root, int low, int high) {
        return getSum(root, low, high);
    }
};