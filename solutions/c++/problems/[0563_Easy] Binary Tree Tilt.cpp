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
    map<TreeNode *, int> sum;
    map<TreeNode *, int> tilt;

    int getTilt(TreeNode *root) {
        if (tilt[root]) return tilt[root];
        int leftSum = 0, rightSum = 0;
        if (root->left) leftSum = getSum(root->left);
        if (root->right) rightSum = getSum(root->right);
        tilt[root] = abs(leftSum - rightSum);
        return tilt[root];
    }

    int getSum(TreeNode *root) {
        if (sum[root]) return sum[root];
        int leftSum = 0, rightSum = 0;
        if (root->left) leftSum = getSum(root->left);
        if (root->right) rightSum = getSum(root->right);
        sum[root] = leftSum + rightSum + root->val;
        return sum[root];
    }

    int findTilt(TreeNode *root) {
        if (!root) return 0;
        queue<vector<TreeNode *>> bfs;
        bfs.push({root});
        int totalTilt = 0;
        while (!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<TreeNode *> nextLevel;
            for (auto node: currLevel) {
                totalTilt += getTilt(node);
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
            }
            bfs.pop();
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return totalTilt;
    }
};