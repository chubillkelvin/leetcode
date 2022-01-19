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
    ListNode *sortList(ListNode *head) {
        vector<int> nums;
        auto curr = head;
        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }
        sort(nums.begin(), nums.end());
        curr = head;
        int idx = 0;
        while (curr) {
            curr->val = nums[idx++];
            curr = curr->next;
        }
        return head;
    }
};