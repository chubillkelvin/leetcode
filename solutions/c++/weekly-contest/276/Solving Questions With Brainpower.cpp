#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        vector<long long> memo(n, 0);
        long long maxSoFar = 0;
        for (int i = 0; i < n; i++) {
            int point = questions[i][0];
            int power = questions[i][1];
            if (i + 1 < n) memo[i + 1] = max(memo[i + 1], memo[i]);
            memo[i] += point;
            int next = i + power + 1;
            if (next < n) memo[next] = max(memo[next], memo[i]);
            maxSoFar = max(maxSoFar, memo[i]);
        }
        return maxSoFar;
    }
};