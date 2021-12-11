#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0) return y;
        return gcd(y % x, x);
    }

    int nthMagicalNumber(int n, int a, int b) {
        int MOD = 1e9 + 7;
        int lcm = a / gcd(a, b) * b;
        long long lo = 0;
        long long hi = (long) n * min(a, b);
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            if (mid / a + mid / b - mid / lcm < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        return lo % MOD;
    }
};