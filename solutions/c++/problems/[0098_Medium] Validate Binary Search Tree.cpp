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
    unordered_map<TreeNode *, vector<int>> minMax;
    unordered_map<TreeNode *, bool> validTree;

    vector<int> minMaxKey(TreeNode *root) {
        if (minMax.find(root) != minMax.end()) return minMax[root];
        if (!root->left && !root->right) return {root->val, root->val};
        int minimum = root->val;
        int maximum = root->val;
        if (root->left) {
            vector<int> leftTree = minMaxKey(root->left);
            minimum = min(minimum, leftTree[0]);
            maximum = max(maximum, leftTree[1]);
        }
        if (root->right) {
            vector<int> rightTree = minMaxKey(root->right);
            minimum = min(minimum, rightTree[0]);
            maximum = max(maximum, rightTree[1]);
        }
        minMax[root] = {minimum, maximum};
        return minMax[root];
    }

    bool isValidBST(TreeNode *root) {
        if (validTree.find(root) != validTree.end()) return validTree[root];
        if (!root->left && !root->right) {
            validTree[root] = true;
            return true;
        }
        bool leftValid = true;
        bool rightValid = true;
        vector<int> minMaxLeft, minMaxRight;
        if (root->left) {
            minMaxLeft = minMaxKey(root->left);
            if (minMaxLeft[1] < root->val) {
                leftValid = isValidBST(root->left);
            } else {
                validTree[root] = false;
                return false;
            }
        }
        if (root->right) {
            minMaxRight = minMaxKey(root->right);
            if (minMaxRight[0] > root->val) {
                rightValid = isValidBST(root->right);
            } else {
                validTree[root] = false;
                return false;
            }
        }
        if (root->left && root->right) {
            if (minMaxLeft[1] > minMaxRight[0]) {
                validTree[root] = false;
                return false;
            }
        }
        validTree[root] = leftValid && rightValid;
        return validTree[root];
    }
};