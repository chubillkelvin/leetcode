#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int sumOfLeftLeaves(TreeNode *root) {
        int total = 0;
        queue<TreeNode *> nodes = {};
        nodes.push(root);
        while (!nodes.empty()) {
            auto curr = nodes.front();
            if (curr->left) {
                nodes.push(curr->left);
                if (!curr->left->left && !curr->left->right) total += curr->left->val;
            }
            if (curr->right) nodes.push(curr->right);
            nodes.pop();
        }
        return total;
    }
};