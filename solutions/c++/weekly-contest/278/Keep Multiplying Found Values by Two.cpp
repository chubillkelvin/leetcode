#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findFinalValue(vector<int> &nums, int original) {
        unordered_map<int, bool> numbers;
        for (int num: nums) numbers[num] = true;
        while (numbers[original]) {
            original *= 2;
        }
        return original;
    }
};