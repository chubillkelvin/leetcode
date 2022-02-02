class Solution {
public:
    long long maxMatrixSum(vector <vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        long long sum = 0;
        long long negativeCount = 0;
        long long minimum = LLONG_MAX;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                long long curr = matrix[i][j];
                minimum = min(minimum, abs(curr));
                sum += abs(curr);
                if (curr < 0) negativeCount++;
            }
        }
        return negativeCount % 2 == 0 ? sum : sum - minimum * 2;
    }
};