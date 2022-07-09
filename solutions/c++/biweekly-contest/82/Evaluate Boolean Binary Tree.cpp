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
public:
    bool dfs(TreeNode *root) {
        if (!root->left && !root->right) {
            return root->val == 0 ? false : true;
        }
        if (root->val == 2) {
            return dfs(root->left) || dfs(root->right);
        } else {
            return dfs(root->left) && dfs(root->right);
        }
    }

    bool evaluateTree(TreeNode *root) {
        return dfs(root);
    }
};