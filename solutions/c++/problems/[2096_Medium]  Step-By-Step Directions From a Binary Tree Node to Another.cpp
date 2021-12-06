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

    string getDirections(TreeNode *root, int startValue, int destValue) {
        vector<char> toStart = {};
        vector<char> toEnd = {};

        dfs(root, startValue, &toStart);
        dfs(root, destValue, &toEnd);
        while (!toStart.empty() && !toEnd.empty() && toStart.back() == toEnd.back()) {
            toStart.pop_back();
            toEnd.pop_back();
        }
        vector<char> fromStart = vector<char>(toStart.size(), 'U');
        for (auto it = toEnd.rbegin(); it != toEnd.rend(); it++) fromStart.push_back(*it);
        return string(fromStart.begin(), fromStart.end());
    }
};