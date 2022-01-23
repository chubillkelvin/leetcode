#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findLonely(vector<int> &nums) {
        vector<int> lonely;
        vector<int> count(1000001, 0);
        for (int num: nums) count[num]++;
        for (int i = 0; i <= 1000000; i++) {
            if (count[i] != 1) continue;
            if (i > 0 && count[i - 1] > 0) continue;
            if (i < 1000000 && count[i + 1] > 0) continue;
            lonely.push_back(i);
        }
        return lonely;
    }
};