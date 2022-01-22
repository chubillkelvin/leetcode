#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>>
    highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<vector<vector<int>>> bfs;
        bfs.push(vector<vector<int>>({start}));
        visited[start[0]][start[1]] = true;
        vector<vector<int>> ans;
        while (!bfs.empty()) {
            auto currLevel = bfs.front();
            vector<vector<int>> nextLevel;
            for (auto pos: currLevel) {
                int row = pos[0];
                int col = pos[1];
                int val = grid[row][col];
                if (val >= pricing[0] && val <= pricing[1]) ans.push_back(pos);
                if (ans.size() == k) return ans;
                if (row - 1 >= 0 && !visited[row - 1][col] && grid[row - 1][col] != 0) {
                    nextLevel.push_back({row - 1, col});
                    visited[row - 1][col] = true;
                }
                if (col - 1 >= 0 && !visited[row][col - 1] && grid[row][col - 1] != 0) {
                    nextLevel.push_back({row, col - 1});
                    visited[row][col - 1] = true;
                }
                if (col + 1 < cols && !visited[row][col + 1] && grid[row][col + 1] != 0) {
                    nextLevel.push_back({row, col + 1});
                    visited[row][col + 1] = true;
                }
                if (row + 1 < rows && !visited[row + 1][col] && grid[row + 1][col] != 0) {
                    nextLevel.push_back({row + 1, col});
                    visited[row + 1][col] = true;
                }
            }
            bfs.pop();
            if (!nextLevel.empty()) {
                sort(nextLevel.begin(), nextLevel.end(), [&](auto &p1, auto &p2) {
                    if (grid[p2[0]][p2[1]] > grid[p1[0]][p1[1]]) return true;
                    if (grid[p2[0]][p2[1]] < grid[p1[0]][p1[1]]) return false;
                    if (p2[0] > p1[0]) return true;
                    if (p2[0] < p1[0]) return false;
                    if (p2[1] > p1[1]) return true;
                    return false;
                });
                bfs.push(nextLevel);
            }
        }
        return ans;
    }
};