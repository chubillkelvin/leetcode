#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper) {
        int n = differences.size();
        long long total = 0;
        long long mini = INT_MAX;
        long long maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            total += differences[i];
            mini = min(mini, total);
            maxi = max(maxi, total);
        }
        long long range = upper - lower;
        long long diff = max(maxi - mini, max(abs(maxi), abs(mini)));
        long long ans = max((long long) 0, range - diff + 1);
        return ans;
    }
};