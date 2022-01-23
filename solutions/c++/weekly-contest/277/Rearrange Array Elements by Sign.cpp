#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> pos, neg;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (curr >= 0) {
                pos.push_back(curr);
            } else {
                neg.push_back(curr);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n / 2; i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};