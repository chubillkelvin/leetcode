#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSmaller(int curr, int m, int n) {
        int total = 0;
        for (int i = 1; i <= m; i++) {
            total += min(curr / i, n);
        }
        return total;
    }

    int findKthNumber(int m, int n, int k) {
        int high = m * n;
        int low = 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = countSmaller(mid, m, n);
            if (count >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return high;
    }
};