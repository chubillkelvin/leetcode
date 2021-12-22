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
    ListNode *reverseList(ListNode *head) {
        ListNode *newHead = nullptr;
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            if (newHead) {
                curr->next = newHead;
            } else {
                curr->next = nullptr;
            }
            newHead = curr;
            curr = next;
        }
        return newHead;
    }
};