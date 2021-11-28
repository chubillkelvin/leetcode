#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumDeletions(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) return n;
        int minimum = 100000000;
        int maximum = -100000000;
        for (int num: nums) {
            minimum = min(minimum, num);
            maximum = max(maximum, num);
        }

        int minIndex = -1;
        int maxIndex = -1;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (curr == minimum) minIndex = i;
            if (curr == maximum) maxIndex = i;
            if (minIndex != -1 && maxIndex != -1) break;
        }

        int delMin = min(minIndex + 1, n - minIndex);
        int delMax = min(maxIndex + 1, n - maxIndex);
        if (delMin <= delMax) {
            bool minIsFront = minIndex + 1 <= n - minIndex;
            if (minIsFront) {
                delMax = min(maxIndex + 1 - delMin, n - maxIndex);
            } else {
                delMax = min(maxIndex + 1, n - maxIndex - delMin);
            }
        } else {
            bool maxIsFront = maxIndex + 1 <= n - maxIndex;
            if (maxIsFront) {
                delMin = min(minIndex + 1 - delMax, n - minIndex);
            } else {
                delMin = min(minIndex + 1, n - minIndex - delMax);
            }
        }
        return delMin + delMax;
    }
};