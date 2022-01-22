/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<vector<TreeNode*>> bfs;
        bfs.push({root});
        while(!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<TreeNode*> nextLevel;
            bool foundTarget = false;
            for(auto node: currLevel) {
                if (node == u) {
                    foundTarget = true;
                    continue;
                } else if (foundTarget) {
                    return node;
                } else {
                    if (node->left) nextLevel.push_back(node->left);
                    if (node->right) nextLevel.push_back(node->right);
                }
            }
            bfs.pop();
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return nullptr;
    }
};