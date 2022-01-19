/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node *copyRandomList(Node *head) {
        if (!head) return head;
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            auto copyNode = new Node(curr->val);
            copyNode->next = next;
            copyNode->random = curr->random;
            curr->next = copyNode;
            curr = next;
        }
        curr = head;
        while (curr) {
            auto copiedNode = curr->next;
            if (copiedNode->random) copiedNode->random = copiedNode->random->next;
            curr = copiedNode->next;
        }
        curr = head;
        auto newHead = head->next;
        while (curr) {
            auto copiedNode = curr->next;
            auto next = copiedNode->next;
            curr->next = next;
            if (next) {
                copiedNode->next = next->next;
            }
            curr = next;
        }
        return newHead;
    }
};