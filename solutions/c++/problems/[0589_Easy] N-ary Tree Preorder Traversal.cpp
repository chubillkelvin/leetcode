/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node *root) {
        if (!root) return {};
        vector<int> ans;
        ans.push_back(root->val);
        for (auto child: root->children) {
            auto childOrder = preorder(child);
            ans.insert(ans.end(), childOrder.begin(), childOrder.end());
        }
        return ans;
    }
};