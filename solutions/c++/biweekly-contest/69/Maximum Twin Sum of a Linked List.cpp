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
    int pairSum(ListNode *head) {
        vector<int> nums;
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
        int n = nums.size();
        int maxSum = 0;
        for (int i = 0; i < n; i++) {
            maxSum = max(maxSum, nums[i] + nums[n - 1 - i]);
        }
        return maxSum;
    }
};