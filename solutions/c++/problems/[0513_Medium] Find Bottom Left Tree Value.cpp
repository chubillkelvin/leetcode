#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        int ans = root->val;
        queue<vector<TreeNode *>> nodes = {};
        nodes.push({root});
        while (!nodes.empty()) {
            vector<TreeNode *> currLevel = nodes.front();
            vector<TreeNode *> nextLevel = {};
            bool savedFirstLeaf = false;
            for (TreeNode *node: currLevel) {
                if (node->left) {
                    nextLevel.push_back(node->left);
                    if (!savedFirstLeaf) {
                        ans = node->left->val;
                        savedFirstLeaf = true;
                    }
                }
                if (node->right) {
                    nextLevel.push_back(node->right);
                    if (!savedFirstLeaf) {
                        ans = node->right->val;
                        savedFirstLeaf = true;
                    }
                }
            }
            if (!nextLevel.empty()) nodes.push(nextLevel);
            nodes.pop();
        }
        return ans;
    }
};