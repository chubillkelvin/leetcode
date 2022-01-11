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
    vector<int> nums;
public:
    void evaluate(vector<int> s) {
        int num = 0;
        int exp = 1;
        while (!s.empty()) {
            num += (s.back()) * exp;
            s.pop_back();
            exp *= 2;
        }
        nums.push_back(num);
    }

    void dfs(TreeNode *node, vector<int> &s) {
        s.push_back(node->val);
        if (node->left) {
            dfs(node->left, s);
            s.pop_back();
        }
        if (node->right) {
            dfs(node->right, s);
            s.pop_back();
        }
        if (!node->left && !node->right) {
            evaluate(s);
        }
    }

    int sumRootToLeaf(TreeNode *root) {
        vector<int> s;
        dfs(root, s);
        int ans = 0;
        for (auto num: nums) ans += num;
        return ans;
    }
};