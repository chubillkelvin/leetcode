#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int lo = 0;
        int hi = rows * cols - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / cols][mid % cols] >= target) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return matrix[lo / cols][lo % cols] == target;
    }
};