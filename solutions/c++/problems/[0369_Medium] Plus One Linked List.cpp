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
    ListNode* plusOne(ListNode* head) {
        vector<ListNode*> digits;
        auto curr = head;
        while(curr) {
            digits.push_back(curr);
            curr = curr->next;
        }
        while(!digits.empty() && digits.back()->val == 9) {
            digits.back()->val = 0;
            digits.pop_back();
        }
        if (digits.empty()) {
            auto newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        } else {
            digits.back()->val++;
            return head;
        }
    }
};