#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int> &nums) {
        int n = nums.size();
        int maxLen = 1;
        int left = 0;
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            int not0 = left - 1;
            for (int j = left; j < i; j++) {
                if ((nums[j] & curr) != 0) not0 = j;
            }
            left = not0 + 1;
            maxLen = max(maxLen, i - left + 1);
        }
        return maxLen;
    }
};