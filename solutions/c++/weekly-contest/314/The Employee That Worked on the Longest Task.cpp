#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int hardestWorker(int n, vector<vector<int>> &logs) {
        int id = logs[0][0];
        int time = logs[0][1];
        for (int i = 1; i < logs.size(); i++) {
            int currId = logs[i][0];
            int currTime = logs[i][1] - logs[i - 1][1];
            if (currTime > time) {
                id = currId;
                time = currTime;
            } else if (currTime == time && currId < id) {
                id = currId;
            }
        }
        return id;
    }
};