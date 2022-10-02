#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxSum(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxSum = 0;
        for (int i = 2; i < m; i++) {
            int sum = 0;
            for (int temp = 0; temp < 3; temp++) {
                sum += grid[i - 2][temp];
                sum += grid[i][temp];
            }
            sum += grid[i - 1][1];
            maxSum = max(maxSum, sum);
            for (int j = 3; j < n; j++) {
                sum -= grid[i - 2][j - 3];
                sum -= grid[i][j - 3];
                sum -= grid[i - 1][j - 2];
                sum += grid[i - 2][j];
                sum += grid[i][j];
                sum += grid[i - 1][j - 1];
                maxSum = max(maxSum, sum);
            }
        }
        return maxSum;
    }
};