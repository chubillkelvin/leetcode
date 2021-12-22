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
    void reorderList(ListNode *head) {
        int n = 0;
        auto curr = head;
        while (curr) {
            n++;
            curr = curr->next;
        }
        // get end of chain node
        int endNodeIndex = n / 2;
        // find start of second half chain
        auto endNode = head;
        int count = 0;
        while (count != endNodeIndex) {
            endNode = endNode->next;
            count++;
        }
        // reverse node order and get original last node as head
        ListNode *secondHead = nullptr;
        curr = endNode->next;
        while (curr) {
            auto next = curr->next;
            if (secondHead) {
                curr->next = secondHead;
            } else {
                curr->next = nullptr;
            }
            secondHead = curr;
            curr = next;
        }
        endNode->next = nullptr;
        // merge chain
        auto curr1 = head;
        auto curr2 = secondHead;
        while (curr1 && curr2) {
            auto next1 = curr1->next;
            auto next2 = curr2->next;
            curr1->next = curr2;
            curr1 = next1;
            curr2->next = next1;
            curr2 = next2;
        }
    }
};