#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *removeElements(ListNode *head, int val) {
        ListNode *pointerToHead = new ListNode(0, head);
        ListNode *prev = pointerToHead;
        ListNode *curr = head;
        while (curr) {
            if (curr->val == val) {
                prev->next = curr->next;
            } else {
                prev = curr;
            }
            curr = curr->next;
        }
        return pointerToHead->next;
    }
};