#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        int n = nums.size();
        vector<int> maxRight(n, 0);
        maxRight[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) maxRight[i] = maxRight[i + 1] | nums[i];
        unordered_map<int, int> mp;
        vector<int> ans(n, 1);
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            if (num != 0) {
                auto b = bitset<32>(num).to_string();
                for (int j = 0; j < b.size(); j++) {
                    if (b[j] == '1') mp[j] = i;
                }
            }
            auto right = bitset<32>(maxRight[i]).to_string();
            int maxIndex = i;
            for (int j = 0; j < right.size(); j++) {
                if (right[j] == '1') {
                    maxIndex = max(maxIndex, mp[j]);
                }
            }
            ans[i] = maxIndex - i + 1;
        }
        return ans;
    }
};