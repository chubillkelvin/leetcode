#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool divideArray(vector<int> &nums) {
        vector<int> memo(501, 0);
        for (int num: nums) memo[num]++;
        for (int num: memo) if (num % 2 != 0) return false;
        return true;
    }
};