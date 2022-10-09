#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfPaths(vector<vector<int>> &grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int MOD = 1e9 + 7;
        vector<vector<vector<long long>>> memo(m, vector<vector<long long>>(n, vector<long long>(k, 0)));
        memo[0][0][grid[0][0] % k] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int num = grid[i][j];
                for (int x = 0; x < k; x++) {
                    int modded = (x + num) % k;
                    if (i > 0) memo[i][j][modded] += memo[i - 1][j][x];
                    if (j > 0) memo[i][j][modded] += memo[i][j - 1][x];
                    memo[i][j][modded] %= MOD;
                }
            }
        }
        return memo[m - 1][n - 1][0];
    }
};