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
    ListNode *middleNode(ListNode *head) {
        int count = 0;
        auto curr = head;
        while (curr) {
            count++;
            curr = curr->next;
        }
        int target = count / 2;
        int index = 0;
        curr = head;
        while (index != target) {
            curr = curr->next;
            index++;
        }
        return curr;
    }
};