#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>> &matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> ans = vector<vector<int>>(rows + 1, vector<int>(cols + 1, 0));
        int maxSoFar = 0;
        for (int i = 1; i <= rows; i++) {
            for (int j = 1; j <= cols; j++) {
                char curr = matrix[i - 1][j - 1];
                if (curr == '0') {
                    ans[i][j] = 0;
                } else {
                    int size = 1;
                    int maxSize = ans[i - 1][j - 1] + 1;
                    for (int k = 1; k < maxSize; k++) {
                        if (matrix[i - 1 - k][j - 1] == '0' || matrix[i - 1][j - 1 - k] == '0') {
                            break;
                        } else {
                            size++;
                        }
                    }
                    ans[i][j] = size;
                    maxSoFar = max(maxSoFar, size);
                }
            }
        }
        return pow(maxSoFar, 2);
    }
};