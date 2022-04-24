#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<vector<int>> &nums) {
        map<int, int> mp;
        for (auto arr: nums) {
            for (int num: arr) mp[num]++;
        }
        vector<int> ans;
        for (auto p: mp) {
            if (p.second == nums.size()) ans.push_back(p.first);
        }
        return ans;
    }
};