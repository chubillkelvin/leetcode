#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>> &matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        priority_queue<int> ans;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans.push(matrix[i][j]);
                if (ans.size() > k) ans.pop();
            }
        }
        return ans.top();
    }
};