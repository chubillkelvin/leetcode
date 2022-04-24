#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool inside(int currX, int currY, vector<int> circle) {
        int x = circle[0];
        int y = circle[1];
        int r = circle[2];
        return sqrt(pow(x - currX, 2) + pow(y - currY, 2)) <= r;
    }

    int countLatticePoints(vector<vector<int>> &circles) {
        int count = 0;
        unordered_map<int, unordered_map<int, bool>> counted;
        for (auto circle: circles) {
            int x = circle[0];
            int y = circle[1];
            int r = circle[2];
            for (int i = x - r; i <= x + r; i++) {
                for (int j = y - r; j <= y + r; j++) {
                    if (!counted[i][j] && inside(i, j, circle)) {
                        counted[i][j] = true;
                        count++;
                    }
                }
            }
        }
        return count;
    }
};