#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canReach(vector<int> &arr, int start) {
        int n = arr.size();
        vector<bool> visited = vector<bool>(n, false);
        queue<vector<int>> bfs;
        bfs.push({start});
        while (!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<int> nextLevel = {};
            for (auto curr: currLevel) {
                int val = arr[curr];
                if (val == 0) return true;
                if (visited[curr]) continue;
                visited[curr] = true;
                int prev = curr - val;
                int next = curr + val;
                if (prev >= 0) nextLevel.push_back(prev);
                if (next < n) nextLevel.push_back(next);
            }
            bfs.pop();
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return false;
    }
};