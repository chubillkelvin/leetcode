#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *oddEvenList(ListNode *head) {
        if (!head || !head->next) return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *evenHead = head->next;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};