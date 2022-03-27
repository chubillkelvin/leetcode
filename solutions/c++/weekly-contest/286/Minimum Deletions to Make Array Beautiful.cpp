#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDeletion(vector<int> &nums) {
        vector<int> temp;
        for (int num: nums) {
            if (temp.size() % 2 == 0 || num != temp.back()) {
                temp.push_back(num);
            }
        }
        return nums.size() - temp.size() + (temp.size() % 2 == 0 ? 0 : 1);
    }
};