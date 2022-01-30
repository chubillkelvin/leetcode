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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        priority_queue<int> nums;
        queue<vector<TreeNode*>> bfs;
        vector<TreeNode*> temp;
        if (root1) temp.push_back(root1);
        if (root2) temp.push_back(root2);
        bfs.push(temp);
        while(!bfs.empty()) {
            auto curr = bfs.front();
            vector<TreeNode*> next;
            for(auto node: curr) {
                nums.push(node->val * -1);
                if (node->left) next.push_back(node->left);
                if (node->right) next.push_back(node->right);
            }
            bfs.pop();
            if(!next.empty()) bfs.push(next);
        }
        vector<int> ans;
        while(!nums.empty()) {
            ans.push_back(nums.top() * -1);
            nums.pop();
        }
        return ans;
    }
};