#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> sorted = vector<int>(nums.begin(), nums.end());
        sort(sorted.begin(), sorted.end(), greater<>());
        map<int, int> res;
        for (int i = 0; i < k; i++) {
            res[sorted[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (res[curr] > 0) {
                ans.push_back(curr);
                res[curr]--;
            }
        }
        return ans;
    }
};