#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool findSubarrays(vector<int> &nums) {
        int n = nums.size();
        unordered_set<int> sum;
        int temp = 0;
        for (int i = 0; i < n; i++) {
            temp += nums[i];
            if (i > 0) {
                if (sum.count(temp)) return true;
                sum.insert(temp);
                temp -= nums[i - 1];
            }
        }
        return false;
    }
};