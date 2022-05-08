#include <bits/stdc++.h>

using namespace std;

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
    int count = 0;
public:
    pair<int, int> dfs(TreeNode *root) {
        int sum = root->val;
        int nodeCount = 1;
        if (root->left) {
            auto left = dfs(root->left);
            sum += left.first;
            nodeCount += left.second;
        }
        if (root->right) {
            auto right = dfs(root->right);
            sum += right.first;
            nodeCount += right.second;
        }
        if (root->val == sum / nodeCount) count++;
        return {sum, nodeCount};
    }

    int averageOfSubtree(TreeNode *root) {
        if (!root) return 0;
        dfs(root);
        return count;
    }
};