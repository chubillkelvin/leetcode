class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector <vector<double>> levels(101, vector<double>(101, 0));
        levels[0][0] = poured;
        for (int i = 0; i <= query_row; i++) {
            for (int j = 0; j <= i; j++) {
                double amount = max(0.0, (levels[i][j] - 1.0) / 2.0);
                levels[i + 1][j] += amount;
                levels[i + 1][j + 1] += amount;
            }
        }
        return min(1.0, levels[query_row][query_glass]);
    }
};