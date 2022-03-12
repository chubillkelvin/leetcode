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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        auto prev = new ListNode();
        auto curr = l1;
        auto ans = curr;
        int temp = 0;
        while (l2 || temp > 0) {
            if (!curr) {
                curr = new ListNode(0);
                prev->next = curr;
            }
            if (l2) {
                curr->val += l2->val;
                l2 = l2->next;
            }
            curr->val += temp;
            temp = 0;
            if (curr->val >= 10) {
                curr->val -= 10;
                temp++;
            }
            prev = curr;
            curr = curr->next;
        }
        return ans;
    }
};