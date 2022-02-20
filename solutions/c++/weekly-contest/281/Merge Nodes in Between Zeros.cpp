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
    ListNode *mergeNodes(ListNode *head) {
        auto toHead = new ListNode();
        auto tail = toHead;
        auto curr = head;
        ListNode *currZero = nullptr;
        int sum = 0;
        while (curr) {
            if (!currZero) {
                if (curr->val == 0) {
                    currZero = curr;
                } else {
                    tail->next = curr;
                    tail = tail->next;
                }
            } else {
                if (curr->val != 0) {
                    sum += curr->val;
                    if (curr->next == nullptr) tail->next = currZero->next;
                } else {
                    if (sum != 0) {
                        tail->next = new ListNode(sum);
                        tail = tail->next;
                        sum = 0;
                    }
                    currZero = curr;
                }
            }
            curr = curr->next;
        }
        return toHead->next;
    }
};