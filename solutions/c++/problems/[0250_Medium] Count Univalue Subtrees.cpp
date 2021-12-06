#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<TreeNode *, bool> univalue;

    bool isUnivalue(TreeNode *root) {
        if (univalue[root]) return univalue[root];
        if (root->left) {
            bool isLeftUni;
            if (univalue[root->left]) {
                isLeftUni = univalue[root->left];
            } else {
                isLeftUni = isUnivalue(root->left);
                univalue[root->left] = isLeftUni;
            }
            if (!isLeftUni) {
                univalue[root] = false;
                return false;
            }
            if (root->left->val != root->val) {
                univalue[root] = false;
                return false;
            }
        }
        if (root->right) {
            bool isRightUni;
            if (univalue[root->right]) {
                isRightUni = univalue[root->right];
            } else {
                isRightUni = isUnivalue(root->right);
                univalue[root->right] = isRightUni;
            }
            if (!isRightUni) {
                univalue[root] = false;
                return false;
            }
            if (root->right->val != root->val) {
                univalue[root] = false;
                return false;
            }
        }
        univalue[root] = true;
        return true;
    }

    int countUnivalSubtrees(TreeNode *root) {
        if (!root) return 0;
        int count = 0;
        queue<vector<TreeNode *>> bfs = {};
        bfs.push({root});
        while (!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<TreeNode *> nextLevel = {};
            for (auto node: currLevel) {
                if (isUnivalue(node)) count++;
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            bfs.pop();
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return count;
    }
};