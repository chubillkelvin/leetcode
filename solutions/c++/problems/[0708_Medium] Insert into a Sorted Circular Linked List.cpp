#include <bits/stdc++.h>

using namespace std;

/*
class Node {
public:
    int val;
    Node *next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node *_next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node *insert(Node *head, int insertVal) {
        if (!head) {
            Node *node = new Node(insertVal);
            node->next = node;
            return node;
        }

        Node *curr = head;
        while (true) {
            // all numbers are the same
            if (curr->next == head && curr->val == curr->next->val) {
                curr->next = new Node(insertVal, head);
                return head;
            }

            // insertValue larger than all numbers
            if (curr->val > curr->next->val && insertVal > curr->val) {
                curr->next = new Node(insertVal, curr->next);
                return head;
            }

            // insertValue smaller than all numbers
            if (curr->val > curr->next->val && insertVal < curr->next->val) {
                curr->next = new Node(insertVal, curr->next);
                return head;
            }

            // normal cases
            if (curr->val <= curr->next->val) {
                if (curr->val <= insertVal && curr->next->val >= insertVal) {
                    curr->next = new Node(insertVal, curr->next);
                    return head;
                }
            } else {
                if (curr->next->val >= insertVal) {
                    curr->next = new Node(insertVal, curr->next);
                    return head;
                }
            }
            curr = curr->next;
        }
    }
};