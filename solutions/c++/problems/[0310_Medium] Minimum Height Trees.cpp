#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<set<int>> adj;

    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges) {
        if (n == 1) return {0};
        if (n == 2) return edges[0];

        adj = vector<set<int>> (n, set<int>{});
        for (auto edge: edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            if (adj[i].size() == 1) leaves.push_back(i);
        }

        while (n > 2) {
            n -= leaves.size();
            vector<int> newLeaves;
            for (int leaf: leaves) {
                for (auto node: adj[leaf]) {
                    adj[node].erase(leaf);
                    if (adj[node].size() == 1) newLeaves.push_back(node);
                }
            }
            leaves = newLeaves;
        }
        return leaves;
    }
};