#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi = x;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if ((long) mid * mid >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return (long) lo * lo > x ? lo - 1 : lo;
    }
};