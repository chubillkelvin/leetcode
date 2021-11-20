#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int> &nums) {
        for (int i = 1; i < nums.size(); i += 2) {
            int prev = nums[i - 1];
            int curr = nums[i];
            if (prev != curr) {
                return prev;
            }
        }
        return nums[nums.size() - 1];
    }
};
