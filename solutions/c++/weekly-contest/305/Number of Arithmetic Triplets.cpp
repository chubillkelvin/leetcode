#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int arithmeticTriplets(vector<int> &nums, int diff) {
        int n = nums.size();
        unordered_set<int> s;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int curr = nums[i];
            if (s.count(curr - diff) && s.count(curr - 2 * diff)) count++;
            s.insert(curr);
        }
        return count;
    }
};