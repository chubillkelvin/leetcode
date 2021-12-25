#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    vector<set<int>> adj;
    vector<bool> visited;
    set<int> currPath;
    bool possible = true;

    void top_sort(int index, vector<int> &ans) {
        if (currPath.count(index) > 0) {
            possible = false;
            return;
        }
        if (visited[index]) return;
        visited[index] = true;
        currPath.insert(index);
        if (!adj[index].empty()) {
            for (auto nextIndex: adj[index]) {
                top_sort(nextIndex, ans);
                currPath.erase(nextIndex);
                if (!possible) return;
            }
        }
        ans.push_back(index);
    }

    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        n = numCourses;
        adj = vector<set<int>>(n);
        visited = vector<bool>(n, false);
        for (auto req: prerequisites) adj[req[0]].insert(req[1]);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            currPath.clear();
            top_sort(i, ans);
            if (!possible) return {};
        }
        return ans;
    }
};