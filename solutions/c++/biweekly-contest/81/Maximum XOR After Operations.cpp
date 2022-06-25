#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumXOR(vector<int> &nums) {
        int ans = 0;
        for (int num: nums) ans |= num;
        return ans;
    }
};