class Solution {
    public int[][] multiply(int[][] mat1, int[][] mat2) {
        int m = mat1.length;
        int k = mat2.length;
        int n = mat2[0].length;
        int[][] ans = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int x = 0; x < k; x++) {
                    ans[i][j] += mat1[i][x] * mat2[x][j];
                }
            }
        }
        return ans;
    }
}
