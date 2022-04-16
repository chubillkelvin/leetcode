#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findClosestNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int val = INT_MAX;
        for (int num: nums) {
            int curr = abs(num);
            if (curr <= diff) {
                diff = curr;
                val = num;
            }
        }
        return val;
    }
};