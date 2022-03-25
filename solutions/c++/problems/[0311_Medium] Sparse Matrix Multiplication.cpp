class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2) {
        int m = mat1.size();
        int k = mat2.size();
        int n = mat2[0].size();
        vector<vector<int>> ans = vector<vector<int>>(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for (int x = 0; x < k; x++) {
                    ans[i][j] += mat1[i][x] * mat2[x][j];
                }
            }
        }
        return ans;
    }
};
