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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> ans = {};
        if (root == nullptr) return ans;
        queue<vector<TreeNode *>> levels = {};
        levels.push({root});
        while (!levels.empty()) {
            auto currLevel = levels.front();
            vector<int> currAns = {};
            vector<TreeNode *> nextLevel = {};
            for (auto node: currLevel) {
                currAns.push_back(node->val);
                if (node->left != nullptr) nextLevel.push_back(node->left);
                if (node->right != nullptr) nextLevel.push_back(node->right);
            }
            ans.push_back(currAns);
            if (!nextLevel.empty()) {
                levels.push(nextLevel);
            }
            levels.pop();
        }
        return ans;
    }
};