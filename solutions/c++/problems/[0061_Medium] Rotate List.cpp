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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) return nullptr;
        int size = 0;
        auto curr = head;
        ListNode *last;
        while (curr) {
            if (!curr->next) last = curr;
            size++;
            curr = curr->next;
        }
        last->next = head;
        k %= size;
        int count = size - k - 1;
        curr = head;
        while (count > 0) {
            count--;
            curr = curr->next;
        }
        auto newHead = curr->next;
        curr->next = nullptr;
        return newHead;
    }
};