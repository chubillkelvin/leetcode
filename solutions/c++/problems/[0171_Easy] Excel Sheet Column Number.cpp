class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        int col = 0;
        long mul = pow(26, n - 1);
        for (int i = 0; i < n; i++) {
            col += (columnTitle[i] - 'A' + 1) * mul;
            mul /= 26;
        }
        return col;
    }
};