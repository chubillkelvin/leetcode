#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionArray(vector<int> &nums, int k) {
        int n = nums.size();
        std::sort(nums.begin(), nums.end());
        int count = 1;
        int minNum = nums[0];
        for (int i = 1; i < n; i++) {
            int curr = nums[i];
            if (curr - minNum <= k) continue;
            count++;
            minNum = curr;
        }
        return count;
    }
};