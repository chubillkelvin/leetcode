#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostFrequentEven(vector<int> &nums) {
        vector<int> temp;
        for (int num: nums) if (num % 2 == 0) temp.push_back(num);
        nums = temp;
        if (nums.empty()) return -1;
        unordered_map<int, int> count;
        for (int num: nums) count[num]++;
        int minNum = nums[0];
        int maxCount = count[nums[0]];
        for (auto p: count) {
            if (p.second >= maxCount) {
                if (p.second == maxCount) {
                    if (p.first < minNum) minNum = p.first;
                } else {
                    minNum = p.first;
                    maxCount = p.second;
                }
            }
        }
        return minNum;
    }
};