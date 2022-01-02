class Solution {
public:
    int minPathSum(vector <vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> memo(m, vector<int>(n, 0));
        memo[0][0] = grid[0][0];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    memo[i][j] = memo[i][j - 1] + grid[i][j];
                } else if (j == 0) {
                    memo[i][j] = memo[i - 1][j] + grid[i][j];
                } else {
                    memo[i][j] = min(memo[i][j - 1], memo[i - 1][j]) + grid[i][j];
                }
            }
        }
        return memo[m - 1][n - 1];
    }
};