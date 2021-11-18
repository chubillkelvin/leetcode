#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        if (nums.size() == 1) return {};
        set<int> allNums = set<int>(nums.begin(), nums.end());
        vector<int> missing = {};
        for (int test = 1; test <= nums.size(); test++) {
            if (allNums.count(test) == 0) missing.push_back(test);
        }
        return missing;
    }
};