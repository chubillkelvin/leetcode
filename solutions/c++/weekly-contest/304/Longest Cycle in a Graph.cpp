#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int curr;
    Node *next = nullptr;

    Node(int curr) {
        this->curr = curr;
    }
};

class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int n = edges.size();
        vector<Node *> nodes(n);
        for (int i = 0; i < n; i++) nodes[i] = new Node(i);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) nodes[i]->next = nodes[edges[i]];
        }
        int maxLen = -1;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            auto node = nodes[i];
            int count = 0;
            unordered_map<int, int> nums;
            while (node) {
                if (nums.count(node->curr)) {
                    maxLen = max(maxLen, (int) nums.size() - nums[node->curr]);
                    break;
                }
                if (visited[node->curr]) break;
                visited[node->curr] = true;
                nums[node->curr] = count++;
                node = node->next;
            }
        }
        return maxLen;
    }
};