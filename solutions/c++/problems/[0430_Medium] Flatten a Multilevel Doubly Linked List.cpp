/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node *flatten(Node *head) {
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            if (curr->child) {
                auto childNode = flatten(curr->child);
                curr->next = childNode;
                childNode->prev = curr;
                while (childNode->next) childNode = childNode->next;
                childNode->next = next;
                if (next) next->prev = childNode;
                curr->child = nullptr;
            }
            curr = next;
        }
        return head;
    }
};