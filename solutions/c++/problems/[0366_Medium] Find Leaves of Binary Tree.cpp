#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isLeafNode(TreeNode *node) {
        if (node->left || node->right) return false;
        return true;
    }

    void getLeaf(TreeNode *node, vector<int> *currSet) {
        if (node->left) {
            if (isLeafNode(node->left)) {
                currSet->push_back(node->left->val);
                node->left = nullptr;
            } else {
                getLeaf(node->left, currSet);
            }
        }

        if (node->right) {
            if (isLeafNode(node->right)) {
                currSet->push_back(node->right->val);
                node->right = nullptr;
            } else {
                getLeaf(node->right, currSet);
            }
        }
    }

    vector<vector<int>> findLeaves(TreeNode *root) {
        vector<vector<int>> collectedNodes = {};
        while (root) {
            if (root->left == nullptr && root->right == nullptr) {
                collectedNodes.push_back({root->val});
                break;
            } else {
                vector<int> currSet;
                getLeaf(root, &currSet);
                collectedNodes.push_back(currSet);
            }
        }
        return collectedNodes;
    }
};