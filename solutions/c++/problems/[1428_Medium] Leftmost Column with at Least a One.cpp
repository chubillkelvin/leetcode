#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dimension = binaryMatrix.dimensions();
        int rows = dimension[0];
        int cols = dimension[0];
        int ans = cols;
        for (int i = 0; i < rows; i++) {
            for (int j = ans - 1; j >= 0; j--) {
                int curr = binaryMatrix.get(i, j);
                if (curr == 0) break;
                if (curr == 1) ans = min(ans, j);
            }
        }
        return ans >= cols ? -1 : ans;
    }
};