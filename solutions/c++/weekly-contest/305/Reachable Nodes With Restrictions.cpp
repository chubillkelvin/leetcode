#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> &edges, vector<int> &restricted) {
        unordered_set<int> visited;
        visited.insert(0);
        unordered_set<int> r;
        for (int restrict: restricted) r.insert(restrict);
        vector<unordered_set<int>> adj(n);
        for (auto edge: edges) {
            if (!r.count(edge[0]) && !r.count(edge[1])) {
                adj[edge[0]].insert(edge[1]);
                adj[edge[1]].insert(edge[0]);
            }
        }
        queue<int> bfs;
        bfs.push(0);
        while (!bfs.empty()) {
            auto curr = bfs.front();
            bfs.pop();
            for (int next: adj[curr]) {
                if (!visited.count(next)) {
                    bfs.push(next);
                    visited.insert(next);
                }
            }
        }
        return visited.size();
    }
};