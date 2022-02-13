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
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<vector<Node*>> bfs;
        bfs.push({root});
        ans.push_back({root->val});
        while(!bfs.empty()) {
            auto curr = bfs.front();
            vector<Node*> next;
            vector<int> nextAns;
            for(auto node: curr) {
                for (auto child: node->children) {
                    next.push_back(child);
                    nextAns.push_back(child->val);
                }
            }
            bfs.pop();
            if(!next.empty()) {
                bfs.push(next);
                ans.push_back(nextAns);
            }
        }
        return ans;
    }
};