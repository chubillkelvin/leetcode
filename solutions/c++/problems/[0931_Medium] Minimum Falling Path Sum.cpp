class Solution {
public:
    int minFallingPathSum(vector <vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector <vector<int>> memo(m, vector<int>(n, 0));
        int minSoFar = 100 * 100;
        for (int i = 0; i < n; i++) {
            memo[0][i] = matrix[0][i];
            if (m == 1) minSoFar = min(minSoFar, memo[0][i]);
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (j == 0) {
                    memo[i][j] = min(memo[i - 1][j], memo[i - 1][j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    memo[i][j] = min(memo[i - 1][j - 1], memo[i - 1][j]) + matrix[i][j];
                } else {
                    memo[i][j] = min(min(memo[i - 1][j - 1], memo[i - 1][j]), memo[i - 1][j + 1]) + matrix[i][j];
                }
                if (i == m - 1) {
                    minSoFar = min(minSoFar, memo[i][j]);
                }
            }
        }
        return minSoFar;
    }
};