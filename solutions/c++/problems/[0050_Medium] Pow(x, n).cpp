#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (N < 0) {
            x = 1 / x;
            N *= -1;
        }
        double ans = 1;
        while (N > 0) {
            if (N % 2 == 0) {
                x *= x;
                N /= 2;
            } else {
                ans *= x;
                N--;
            }
        }
        return ans;
    }
};