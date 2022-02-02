class Solution {
public:
    vector<int> findPeakGrid(vector <vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        for (int i = 0; i < m; i++) {
            int maxJ = 0;
            for (int j = 1; j < n; j++) {
                if (mat[i][j] > mat[i][maxJ]) maxJ = j;
            }
            if (i == 0 || mat[i][maxJ] > mat[i - 1][maxJ]) {
                if (i == m - 1 || mat[i][maxJ] > mat[i + 1][maxJ]) {
                    return {i, maxJ};
                }
            }
        }
        return {0, 0};
    }
};