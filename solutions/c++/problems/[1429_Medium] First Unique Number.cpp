#include <bits/stdc++.h>

using namespace std;

struct Node {
    int val;
    struct Node *prev = nullptr, *next = nullptr;
};

class FirstUnique {
public:
    unordered_map<int, int> seen = {};
    struct Node *head = nullptr, *tail = nullptr;

    FirstUnique(vector<int> &nums) {
        for (int num: nums) {
            add(num);
        }
    }

    void appendNode(struct Node **headRef, struct Node **tailRef, int value) {
        auto *curr = new Node;
        curr->val = value;
        if (*headRef == nullptr) {
            *headRef = curr;
            *tailRef = curr;
        } else {
            curr->prev = *tailRef;
            (*tailRef)->next = curr;
            *tailRef = curr;
        }
    }

    void removeNode(struct Node **headRef, struct Node **tailRef, int value) {
        if (*headRef == nullptr) return;

        if ((*headRef)->val == value) {
            auto next = (*headRef)->next;
            *headRef = next;
            if (next != nullptr) {
                next->prev = nullptr;
            }
            return;
        }
        if ((*tailRef)->val == value) {
            auto prev = (*tailRef)->prev;
            *tailRef = prev;
            if (prev != nullptr) {
                prev->next = nullptr;
            }
            return;
        }

        struct Node *curr = *headRef;
        while (curr != nullptr && curr->val != value) {
            curr = curr->next;
        }
        if (curr->val == value) {
            struct Node *prev = curr->prev;
            struct Node *next = curr->next;
            if (prev != nullptr) prev->next = next;
            if (next != nullptr) next->prev = prev;
        }
    }

    int showFirstUnique() {
        return head == nullptr ? -1 : head->val;
    }

    void add(int value) {
        int count = seen[value];
        if (count == 0) {
            appendNode(&head, &tail, value);
        }
        if (count == 1) {
            removeNode(&head, &tail, value);
        }
        seen[value]++;
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */