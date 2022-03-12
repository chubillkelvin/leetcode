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
    ListNode *deleteDuplicates(ListNode *head) {
        auto ptToHead = new ListNode();
        auto prev = ptToHead;
        auto curr = head;
        while (curr) {
            auto next = curr->next;
            if (!next || curr->val != next->val) {
                prev->next = curr;
                prev = curr;
            } else {
                while (next && curr->val == next->val) next = next->next;
            }
            curr = next;
        }
        prev->next = nullptr;
        return ptToHead->next;
    }
};