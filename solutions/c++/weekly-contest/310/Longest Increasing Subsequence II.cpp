// TLE :(

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums, int k) {
        int n = nums.size();
        int maxLen = 1;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int curr = 1;
            auto lb = mp.lower_bound(num - k);
            while (lb != mp.end() && lb->first < num) {
                curr = max(curr, lb->second + 1);
                lb++;
            }
            mp[num] = curr;
            maxLen = max(maxLen, curr);
        }
        return maxLen;
    }
};