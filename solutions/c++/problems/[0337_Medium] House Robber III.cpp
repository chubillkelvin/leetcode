#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rob_notRob(TreeNode *root) {
        vector<int> ans = {0, 0};
        if (root == nullptr) return ans;
        auto left = rob_notRob(root->left);
        auto right = rob_notRob(root->right);
        int robCurr = root->val + left[1] + right[1];
        int notRobCurr = max(left[0], left[1]) + max(right[0], right[1]);
        ans = {robCurr, notRobCurr};
        return ans;
    }

    int rob(TreeNode *root) {
        vector<int> curr = rob_notRob(root);
        return max(curr[0], curr[1]);
    }
};
