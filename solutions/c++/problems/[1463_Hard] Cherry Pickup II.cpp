class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // pad two sides of the columns with 0 to eliminate conditions checking for tabulation
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));
        memo[0][1][n] = grid[0][0] + grid[0][n-1];
        int maxSoFar = memo[0][1][n];
        for(int i = 1; i < m; i++) {
            for(int j = 1; j <= n; j++) {
                for(int k = 1; k <= n; k++) {
                    int currValue = j == k ? grid[i][j-1] : grid[i][j-1] + grid[i][k-1];
                    int maxPrev1 = max(memo[i-1][j-1][k-1], max(memo[i-1][j][k-1], memo[i-1][j+1][k-1]));
                    int maxPrev2 = max(memo[i-1][j-1][k], max(memo[i-1][j][k], memo[i-1][j+1][k]));
                    int maxPrev3 = max(memo[i-1][j-1][k+1], max(memo[i-1][j][k+1], memo[i-1][j+1][k+1]));
                    int maxPrev = max(maxPrev1, max(maxPrev2, maxPrev3));
                    if (maxPrev == -1) continue;
                    memo[i][j][k] = maxPrev + currValue;
                    if (i == m-1) maxSoFar = max(maxSoFar, memo[i][j][k]);
                }
            }
        }
        return maxSoFar;
    }
};