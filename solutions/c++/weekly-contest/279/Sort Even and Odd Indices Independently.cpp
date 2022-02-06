#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int> &nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (i % 2 == 1) {
                odd.push_back(curr);
            } else {
                even.push_back(curr);
            }
        }
        sort(odd.begin(), odd.end(), greater<int>());
        sort(even.begin(), even.end());
        vector<int> ans;
        for (int i = 0; i < even.size(); i++) {
            ans.push_back(even[i]);
            if (i < odd.size()) ans.push_back(odd[i]);
        }
        return ans;
    }
};