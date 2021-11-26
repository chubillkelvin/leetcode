#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        unordered_map<int, bool> mp = {};
        for (int num: nums) {
            mp[num] = true;
        }

        int minSoFar = nums.size() + 1;
        for (int i = nums.size(); i > 0; i--) {
            if (!mp[i]) minSoFar = i;
        }
        return minSoFar;
    }
};
