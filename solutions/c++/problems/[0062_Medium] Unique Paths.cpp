class Solution {
public:
    int uniquePaths(int m, int n) {
        vector <vector<int>> memo(m, vector<int>(n, 1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;
                if (i == 0) {
                    memo[i][j] = memo[i][j - 1];
                } else if (j == 0) {
                    memo[i][j] == memo[i - 1][j];
                } else {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1];
                }
            }
        }
        return memo[m - 1][n - 1];
    }
};