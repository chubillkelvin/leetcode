/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    unordered_map<Node *, Node *> nodeMap;
public:
    void clone(Node *node) {
        nodeMap[node] = new Node(node->val);
        auto currClone = nodeMap[node];
        for (auto neighbor: node->neighbors) {
            if (!nodeMap[neighbor]) clone(neighbor);
            currClone->neighbors.push_back(nodeMap[neighbor]);
        }
    }

    Node *cloneGraph(Node *node) {
        if (!node) return node;
        clone(node);
        return nodeMap[node];
    }
};