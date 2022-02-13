#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long minimumRemoval(vector<int> &beans) {
        long long n = beans.size();
        if (n == 1) return 0;
        sort(beans.begin(), beans.end());
        long long sum = 0;
        for (int num: beans) sum += num - beans[0];
        long long minSoFar = sum;
        for (long long i = 1; i < n; i++) {
            int prev = beans[i - 1];
            int num = beans[i];
            sum -= (n - i) * (num - prev);
            sum += prev;
            minSoFar = min(minSoFar, sum);
        }
        return minSoFar;
    }
};