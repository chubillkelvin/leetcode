#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divideCandies(vector<int> &candies, long long k, int target) {
        long long piles = 0;
        for (int c: candies) piles += (c / target);
        return piles >= k;
    }

    int maximumCandies(vector<int> &candies, long long k) {
        int lo = 1;
        int hi = INT_MIN;
        for (int num: candies) hi = max(hi, num);
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;
            if (divideCandies(candies, k, mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        return divideCandies(candies, k, lo) ? lo : 0;
    }
};