/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
    unordered_map<Node *, NodeCopy *> copyMap;
public:
    NodeCopy *copyRandomBinaryTree(Node *root) {
        if (!root) return nullptr;
        if (copyMap[root]) return copyMap[root];
        auto nodeCopy = new NodeCopy(root->val);
        copyMap[root] = nodeCopy;
        nodeCopy->left = copyRandomBinaryTree(root->left);
        nodeCopy->right = copyRandomBinaryTree(root->right);
        nodeCopy->random = copyRandomBinaryTree(root->random);
        return nodeCopy;
    }
};