class Solution {
public:
    int minJumps(vector<int> &arr) {
        int n = arr.size();
        if (n == 1) return 0;
        if (arr[0] == arr.back()) return 1;
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[arr[i]].push_back(i);
        }
        vector<bool> visited(n, false);
        int step = 0;
        queue <vector<int>> bfs;
        bfs.push({0});
        while (!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<int> nextLevel;
            for (auto node: currLevel) {
                if (node == n - 1) return step;
                if (!visited[node]) {
                    visited[node] = true;
                    if (node - 1 >= 0 && !visited[node - 1]) nextLevel.push_back(node - 1);
                    if (node + 1 < n && !visited[node + 1]) nextLevel.push_back(node + 1);
                    auto sameNumNodes = pos[arr[node]];
                    for (auto nextNode: sameNumNodes) {
                        if (nextNode != node && !visited[nextNode]) nextLevel.push_back(nextNode);
                    }
                    pos[arr[node]].clear();
                }
            }
            bfs.pop();
            step++;
            if (!nextLevel.empty()) bfs.push(nextLevel);
        }
        return step;
    }
};