class Solution {
public:
    int uniquePathsWithObstacles(vector <vector<int>> &obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector <vector<int>> memo(rows, vector<int>(cols, 0));
        memo[0][0] = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (obstacleGrid[i][j] == 1) {
                    memo[i][j] = 0;
                    continue;
                }
                if (i > 0) {
                    memo[i][j] += memo[i - 1][j];
                }
                if (j > 0) {
                    memo[i][j] += memo[i][j - 1];
                }
            }
        }
        return memo[rows - 1][cols - 1];
    }
};