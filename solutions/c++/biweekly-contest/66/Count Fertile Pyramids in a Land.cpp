#include <bits/stdc++.h>

using namespace std;

// Time Limit Exceeded :(
class Solution {
public:
    int countPyramids(vector<vector<int>> &grid) {
        int upright = 0;
        int inverse = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == 1) {
                    // skip edges
                    if (i == 0 && j == 0) continue;
                    if (i == grid.size() - 1 && j == 0) continue;
                    if (i == 0 && j == grid[i].size() - 1) continue;
                    if (i == grid.size() - 1 && j == grid[i].size() - 1) continue;

                    // check upright
                    if (i < grid.size() - 1) {
                        for (int level = 1; i + level < grid.size(); level++) {
                            if (grid[i + level][j] == 0) break;
                            bool valid = true;
                            for (int expand = 1; expand <= level; expand++) {
                                if (j - expand < 0) {
                                    valid = false;
                                    break;
                                }
                                if (j + expand >= grid[i].size()) {
                                    valid = false;
                                    break;
                                }
                                if (grid[i + level][j - expand] == 0) {
                                    valid = false;
                                    break;
                                }
                                if (grid[i + level][j + expand] == 0) {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid) {
                                upright++;
                            } else {
                                break;
                            }
                        }
                    }

                    // check inverse
                    if (i > 0) {
                        for (int level = 1; i - level >= 0; level++) {
                            if (grid[i - level][j] == 0) break;
                            bool valid = true;
                            for (int expand = 1; expand <= level; expand++) {
                                if (j - expand < 0) {
                                    valid = false;
                                    break;
                                }
                                if (j + expand >= grid[i].size()) {
                                    valid = false;
                                    break;
                                }
                                if (grid[i - level][j - expand] == 0) {
                                    valid = false;
                                    break;
                                }
                                if (grid[i - level][j + expand] == 0) {
                                    valid = false;
                                    break;
                                }
                            }
                            if (valid) {
                                inverse++;
                            } else {
                                break;
                            }
                        }
                    }
                }
            }
        }
        return upright + inverse;
    }
};