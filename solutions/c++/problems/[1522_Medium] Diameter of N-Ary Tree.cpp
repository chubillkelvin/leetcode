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
    int ans = 0;
public:
    int height(Node *root) {
        if (!root) return 0;

        int max1 = 0;
        int max2 = 0;
        for (auto node: root->children) {
            int h = height(node);
            if (h > max1) {
                max2 = max1;
                max1 = h;
            } else if (h > max2) {
                max2 = h;
            }
        }
        ans = max(ans, max1 + max2);
        return max1 + 1;
    }

    int diameter(Node *root) {
        height(root);
        return ans;
    }
};