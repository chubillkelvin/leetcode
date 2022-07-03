// TLE :(
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long count = m * n;
        int MOD = 1e9 + 7;
        unordered_map<int, unordered_map<int, long long>> memo;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                memo[i][j] = 1;
            }
        }
        while (!memo.empty()) {
            unordered_map<int, unordered_map<int, long long>> next;
            for (auto p: memo) {
                for (auto p2: p.second) {
                    int i = p.first;
                    int j = p2.first;
                    if (i - 1 >= 0 && grid[i - 1][j] > grid[i][j]) {
                        next[i - 1][j] += memo[i][j];
                        count += memo[i][j];
                    }
                    if (i + 1 < m && grid[i + 1][j] > grid[i][j]) {
                        next[i + 1][j] += memo[i][j];
                        count += memo[i][j];
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] > grid[i][j]) {
                        next[i][j - 1] += memo[i][j];
                        count += memo[i][j];
                    }
                    if (j + 1 < n && grid[i][j + 1] > grid[i][j]) {
                        next[i][j + 1] += memo[i][j];
                        count += memo[i][j];
                    }
                }
            }
            count %= MOD;
            if (next.empty()) break;
            memo = next;
        }
        return count;
    }
};