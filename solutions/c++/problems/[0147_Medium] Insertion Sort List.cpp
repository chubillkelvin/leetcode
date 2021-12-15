#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {
        auto pointerToHead = new ListNode(-9999);

        auto curr = head;
        while (curr) {
            auto next = curr->next;

            auto prev = pointerToHead;
            while (prev->next && prev->next->val < curr->val) {
                prev = prev->next;
            }
            curr->next = prev->next;
            prev->next = curr;

            curr = next;
        }
        return pointerToHead->next;
    }
};
