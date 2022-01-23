#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countElements(vector<int> &nums) {
        int n = nums.size();
        if (n <= 2) return 0;
        sort(nums.begin(), nums.end());
        int start = 0;
        int end = n - 1;
        while (start < end && nums[start] == nums[start + 1]) start++;
        while (end > start && nums[end] == nums[end - 1]) end--;
        return max(end - start - 1, 0);
    }
};