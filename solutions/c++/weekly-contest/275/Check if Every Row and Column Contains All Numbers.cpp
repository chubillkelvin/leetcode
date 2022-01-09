#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValid(vector<vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            vector<int> count(n, 0);
            for (int j = 0; j < n; j++) {
                int curr = matrix[i][j];
                if (count[curr - 1] > 0) return false;
                count[curr - 1]++;
            }
        }
        for (int i = 0; i < n; i++) {
            vector<int> count(m, 0);
            for (int j = 0; j < m; j++) {
                int curr = matrix[j][i];
                if (count[curr - 1] > 0) return false;
                count[curr - 1]++;
            }
        }
        return true;
    }
};