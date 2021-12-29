/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        queue<vector<Node*>> bfs;
        bfs.push({root});
        while(!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<Node*> nextLevel;
            int n = currLevel.size();
            for(int i = 0; i < n; i++) {
                auto node = currLevel[i];
                if (node->left) nextLevel.push_back(node->left);
                if (node->right) nextLevel.push_back(node->right);
                if (i < n - 1) node->next = currLevel[i+1];
            }
            bfs.pop();
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return root;
    }
};