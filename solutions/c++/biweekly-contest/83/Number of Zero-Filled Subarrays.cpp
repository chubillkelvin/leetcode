#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int> &nums) {
        int n = nums.size();
        long long count = 0;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                curr++;
                count += curr;
            } else {
                curr = 0;
            }
        }
        return count;
    }
};