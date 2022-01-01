class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int cities = flights.size();
        int n = days.size();
        vector<vector<int>> dp = vector<vector<int>>(n, vector<int>(cities, -1));
        // base cases
        int maxDays = 0;
        for(int c = 0; c < cities; c++) {
            if (c == 0 || flights[0][c] == 1) {
                dp[0][c] = days[c][0];
                maxDays = max(maxDays, dp[0][c]);
            }
        }
        // dp
        for(int i = 1; i < n; i++) {
            for(int c = 0; c < cities; c++) {
                for(int prev = 0; prev < cities; prev++) {
                    if ((prev == c || flights[prev][c] == 1) && dp[i-1][prev] >= 0) {
                        dp[i][c] = max(dp[i][c], dp[i-1][prev] + days[c][i]);
                    }
                }
                maxDays = max(maxDays, dp[i][c]);
            }
        }
        return maxDays;
    }
};