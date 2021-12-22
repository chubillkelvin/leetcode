#include <bits/stdc++.h>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        ListNode *ptToHead = new ListNode();
        auto curr = ptToHead;
        auto curr1 = list1;
        auto curr2 = list2;
        while (curr1 || curr2) {
            if (!curr1) {
                curr->next = curr2;
                curr2 = curr2->next;
            } else if (!curr2) {
                curr->next = curr1;
                curr1 = curr1->next;
            } else {
                if (curr1->val <= curr2->val) {
                    curr->next = curr1;
                    curr1 = curr1->next;
                } else {
                    curr->next = curr2;
                    curr2 = curr2->next;
                }
            }
            curr = curr->next;
        }
        return ptToHead->next;
    }
};