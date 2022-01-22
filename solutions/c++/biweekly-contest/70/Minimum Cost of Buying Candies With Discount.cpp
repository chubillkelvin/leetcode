#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCost(vector<int> &cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int total = 0;
        int bought = 0;
        for (int i = n - 1; i >= 0; i--) {
            int curr = cost[i];
            if (bought < 2) {
                bought++;
                total += curr;
            } else {
                bought = 0;
            }
        }
        return total;
    }
};