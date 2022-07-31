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
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        int n = edges.size();
        vector<Node *> nodes(n);
        for (int i = 0; i < n; i++) nodes[i] = new Node(i);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) nodes[i]->next = nodes[edges[i]];
        }
        unordered_map<int, int> visited1;
        int count1 = 0;
        auto n1 = nodes[node1];
        while (n1) {
            if (visited1.count(n1->curr)) break;
            visited1[n1->curr] = count1++;
            n1 = n1->next;
        }

        int ans1 = INT_MAX;
        int ans2 = -1;
        int count2 = 0;
        unordered_map<int, int> visited2;
        auto n2 = nodes[node2];
        while (n2) {
            if (visited2.count(n2->curr)) break;
            visited2[n2->curr] = count2++;
            if (visited1.count(n2->curr)) {
                if (max(visited1[n2->curr], visited2[n2->curr]) <= ans1) {
                    if (max(visited1[n2->curr], visited2[n2->curr]) == ans1 && ans2 != -1) {
                        ans2 = min(ans2, n2->curr);
                    } else {
                        ans2 = n2->curr;
                    }
                    ans1 = max(visited1[n2->curr], visited2[n2->curr]);
                }
            }
            n2 = n2->next;
        }
        return ans2;
    }
};