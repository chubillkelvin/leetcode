#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCost(vector<int> &startPos, vector<int> &homePos, vector<int> &rowCosts, vector<int> &colCosts) {
        int rowCost = 0;
        int startRow = startPos[0];
        int homeRow = homePos[0];
        if (startRow < homeRow) {
            for (int i = startRow + 1; i <= homeRow; i++) {
                rowCost += rowCosts[i];
            }
        } else {
            for (int i = startRow - 1; i >= homeRow; i--) {
                rowCost += rowCosts[i];
            }
        }

        int colCost = 0;
        int startCol = startPos[1];
        int homeCol = homePos[1];
        if (startCol < homeCol) {
            for (int i = startCol + 1; i <= homeCol; i++) {
                colCost += colCosts[i];
            }
        } else {
            for (int i = startCol - 1; i >= homeCol; i--) {
                colCost += colCosts[i];
            }
        }
        return rowCost + colCost;
    }
};