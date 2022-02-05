#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumSum(int num) {
        string number = to_string(num);
        vector<char> nums;
        for (char c: number) nums.push_back(c);
        sort(nums.begin(), nums.end());
        return ((nums[0] - '0') * 10 + (nums[2] - '0')) + ((nums[1] - '0') * 10 + (nums[3] - '0'));
    }
};