#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int equalPairs(vector<vector<int>> &grid) {
        int n = grid.size();
        unordered_map<string, int> row;
        for (int i = 0; i < n; i++) {
            string temp;
            for (int num: grid[i]) {
                temp += to_string(num);
                temp += ',';
            }
            row[temp]++;
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            string temp;
            for (int j = 0; j < n; j++) {
                temp += to_string(grid[j][i]);
                temp += ',';
            }
            count += row[temp];
        }
        return count;
    }
};