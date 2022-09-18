#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *reverseOddLevels(TreeNode *root) {
        queue<vector<TreeNode *>> bfs;
        bfs.push({root});
        int level = 0;
        while (!bfs.empty()) {
            auto curr = bfs.front();
            bfs.pop();
            vector<TreeNode *> next;
            vector<int> val;
            for (auto node: curr) {
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
                val.push_back(node->val);
            }
            if (level % 2 != 0) {
                int m = curr.size();
                for (int i = 0; i < m; i++) {
                    curr[i]->val = val[m - 1 - i];
                }
            }
            if (!next.empty()) bfs.push(next);
            level++;
        }
        return root;
    }
};