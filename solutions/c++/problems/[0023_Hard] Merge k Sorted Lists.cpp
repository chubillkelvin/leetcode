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
struct compare {
    bool operator()(ListNode* &node1, ListNode* &node2) {
        return node1->val > node2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* &node1, ListNode* &node2) {return node1->val < node2->val;};
        priority_queue<ListNode*, vector<ListNode*>, compare> p;
        for(auto list: lists) {
            if(list) p.push(list);
        }
        ListNode* toHead = new ListNode();
        auto curr = toHead;
        while(!p.empty()) {
            curr->next = p.top();
            p.pop();
            if (curr->next->next) p.push(curr->next->next);
            curr = curr->next;
        }
        return toHead->next;
    }
};