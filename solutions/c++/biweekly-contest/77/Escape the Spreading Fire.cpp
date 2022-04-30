#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumMinutes(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int GRASS = 0;
        int FIRE = 1;
        int WALL = 2;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<vector<pair<int, int>>>> bfs;
        vector<vector<pair<int, int>>> shortestPaths;
        bfs.push({{{0, 0}}});
        while (!bfs.empty() && shortestPaths.empty()) {
            auto curr = bfs.front();
            bfs.pop();
            vector<vector<pair<int, int>>> next;
            for (auto path: curr) {
                auto x = path.back().first;
                auto y = path.back().second;
                if (x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == GRASS) {
                    visited[x - 1][y] = true;
                    vector<pair<int, int>> nextPath = path;
                    nextPath.push_back({x - 1, y});
                    next.push_back(nextPath);
                }
                if (x + 1 < m && (!visited[x + 1][y] || x + 1 == m - 1 && y == n - 1) && grid[x + 1][y] == GRASS) {
                    visited[x + 1][y] = true;
                    vector<pair<int, int>> nextPath = path;
                    nextPath.push_back({x + 1, y});
                    next.push_back(nextPath);
                    if (nextPath.back().first == m - 1 && nextPath.back().second == n - 1) {
                        shortestPaths.push_back(nextPath);
                    }
                }
                if (y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == GRASS) {
                    visited[x][y - 1] = true;
                    vector<pair<int, int>> nextPath = path;
                    nextPath.push_back({x, y - 1});
                    next.push_back(nextPath);
                }
                if (y + 1 < n && (!visited[x][y + 1] || x == m - 1 && y + 1 == n - 1) && grid[x][y + 1] == GRASS) {
                    visited[x][y + 1] = true;
                    vector<pair<int, int>> nextPath = path;
                    nextPath.push_back({x, y + 1});
                    next.push_back(nextPath);
                    if (nextPath.back().first == m - 1 && nextPath.back().second == n - 1) {
                        shortestPaths.push_back(nextPath);
                    }
                }
            }
            if (!next.empty()) bfs.push(next);
        }
        if (shortestPaths.empty()) return -1;
        vector<vector<int>> graph(m, vector<int>(n, INT_MAX));
        vector<pair<int, int>> fires;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == FIRE) {
                    fires.push_back({i, j});
                    graph[i][j] = 0;
                }
            }
        }
        queue<vector<pair<int, int>>> fireBfs;
        fireBfs.push(fires);
        int currTime = 1;
        while (!fireBfs.empty()) {
            auto curr = fireBfs.front();
            fireBfs.pop();
            vector<pair<int, int>> next;
            for (auto fire: curr) {
                auto x = fire.first;
                auto y = fire.second;
                if (x - 1 >= 0 && graph[x - 1][y] > currTime && grid[x - 1][y] == GRASS) {
                    graph[x - 1][y] = currTime;
                    next.push_back({x - 1, y});
                }
                if (x + 1 < m && graph[x + 1][y] > currTime && grid[x + 1][y] == GRASS) {
                    graph[x + 1][y] = currTime;
                    next.push_back({x + 1, y});
                }
                if (y - 1 >= 0 && graph[x][y - 1] > currTime && grid[x][y - 1] == GRASS) {
                    graph[x][y - 1] = currTime;
                    next.push_back({x, y - 1});
                }
                if (y + 1 < n && graph[x][y + 1] > currTime && grid[x][y + 1] == GRASS) {
                    graph[x][y + 1] = currTime;
                    next.push_back({x, y + 1});
                }
            }
            if (!next.empty()) fireBfs.push(next);
            currTime++;
        }
        int ans = -1;
        for (auto path: shortestPaths) {
            int minDiff = 1e9;
            for (int i = 0; i < path.size(); i++) {
                auto pos = path[i];
                int diff;
                if (i == 0 || i == path.size() - 1) {
                    diff = graph[pos.first][pos.second] - i;

                } else {
                    diff = graph[pos.first][pos.second] - i - 1;
                }
                minDiff = min(minDiff, diff);
            }
            if (minDiff >= 0) {
                if (ans == -1) {
                    ans = minDiff;
                } else {
                    ans = max(ans, minDiff);
                }
            }
        }
        return ans >= 0 ? ans : -1;
    }
};