#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> arrayChange(vector<int> &nums, vector<vector<int>> &operations) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        for (auto op: operations) {
            auto original = mp[op[0]];
            for (int index: original) {
                mp[op[1]].push_back(index);
            }
            mp.erase(op[0]);
        }
        vector<int> ans(n, 0);
        for (auto p: mp) {
            for (auto index: p.second) {
                ans[index] = p.first;
            }
        }
        return ans;
    }
};