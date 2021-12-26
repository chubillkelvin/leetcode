#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> nums;
public:
    Solution(vector<int> &nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        int n = nums.size();
        vector<int> ans = nums;
        for (int i = 0; i < n; i++) {
            int newPosition = rand() % n;
            swap(ans[newPosition], ans[i]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */