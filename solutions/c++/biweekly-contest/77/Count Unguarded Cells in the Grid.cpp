#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>> &guards, vector<vector<int>> &walls) {
        vector<vector<char>> grid(m, vector<char>(n, 'o'));
        for (auto g: guards) {
            grid[g[0]][g[1]] = 'g';
        }
        for (auto w: walls) {
            grid[w[0]][w[1]] = 'w';
        }
        for (auto g: guards) {
            int x = g[0];
            int y = g[1];
            for (int i = x - 1; i >= 0; i--) {
                if (grid[i][y] == 'g' || grid[i][y] == 'w') break;
                grid[i][y] = 'x';
            }
            for (int i = x + 1; i < m; i++) {
                if (grid[i][y] == 'g' || grid[i][y] == 'w') break;
                grid[i][y] = 'x';
            }
            for (int i = y - 1; i >= 0; i--) {
                if (grid[x][i] == 'g' || grid[x][i] == 'w') break;
                grid[x][i] = 'x';
            }
            for (int i = y + 1; i < n; i++) {
                if (grid[x][i] == 'g' || grid[x][i] == 'w') break;
                grid[x][i] = 'x';
            }
        }
        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'o') count++;
            }
        }
        return count;
    }
};