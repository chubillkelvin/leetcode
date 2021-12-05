#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *deleteMiddle(ListNode *head) {
        int n = 1;
        auto prev = head;
        auto curr = head;
        while (curr->next) {
            n++;
            prev = curr;
            curr = curr->next;
        }
        int mid = n / 2;
        if (mid == 0) return nullptr;
        if (mid == n - 1) {
            prev->next = nullptr;
            return head;
        }
        int count = 0;
        prev = curr;
        curr = head;
        auto next = head;
        while (count < mid + 1) {
            prev = curr;
            curr = next;
            next = curr->next;
            count++;
        }
        prev->next = next;
        return head;
    }
};