#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode *newHead = head->next;
        ListNode *prev = new ListNode(0, head);
        ListNode *curr = head;
        ListNode *next = head->next;
        do {
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            prev = curr;
            curr = curr->next;
            next = curr ? curr->next : NULL;
        } while (curr && next);

        return newHead;
    }
};