#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDiff = abs(arr[1] - arr[0]);
        vector<vector<int>> ans;
        ans.push_back({arr[0], arr[1]});
        for (int i = 2; i < n; i++) {
            int prev = arr[i - 1];
            int curr = arr[i];
            int currDiff = curr - prev;
            if (currDiff < minDiff) {
                minDiff = currDiff;
                ans = {};
                ans.push_back({prev, curr});
            } else if (currDiff == minDiff) {
                ans.push_back({prev, curr});
            }
        }
        return ans;
    }
};