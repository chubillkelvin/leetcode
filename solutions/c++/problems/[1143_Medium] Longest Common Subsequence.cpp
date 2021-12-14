#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> ans = vector<vector<int>>(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                char c1 = text1[i - 1];
                char c2 = text2[j - 1];
                if (c1 == c2) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                } else {
                    ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
                }
            }
        }
        return ans[m][n];
    }
};