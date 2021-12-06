#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool dfs(TreeNode *curr, int target, vector<char> *res) {
        if (curr->val == target) return true;
        if (curr->left && dfs(curr->left, target, res)) {
            res->push_back('L');
            return true;
        }
        if (curr->right && dfs(curr->right, target, res)) {
            res->push_back('R');
            return true;
        }
        return false;
    }

    int findDistance(TreeNode *root, int p, int q) {
        vector<char> toP = {};
        vector<char> toQ = {};

        dfs(root, p, &toP);
        dfs(root, q, &toQ);
        while (!toP.empty() && !toQ.empty() && toP.back() == toQ.back()) {
            toP.pop_back();
            toQ.pop_back();
        }
        return toP.size() + toQ.size();
    }
};