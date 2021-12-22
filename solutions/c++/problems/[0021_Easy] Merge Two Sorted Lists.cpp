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
        while (list1 || list2) {
            if (!list1) {
                curr->next = list2;
                list2 = list2->next;
            } else if (!list2) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                if (list1->val <= list2->val) {
                    curr->next = list1;
                    list1 = list1->next;
                } else {
                    curr->next = list2;
                    list2 = list2->next;
                }
            }
            curr = curr->next;
        }
        return ptToHead->next;
    }
};