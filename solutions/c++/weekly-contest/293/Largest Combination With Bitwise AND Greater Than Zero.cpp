#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestCombination(vector<int> &candidates) {
        int maxCount = 0;
        vector<int> count(32, 0);
        for (auto candidate: candidates) {
            auto b = bitset<32>(candidate);
            string s = b.to_string();
            for (int i = 0; i < 32; i++) {
                if (s[i] == '1') {
                    count[i]++;
                    maxCount = max(maxCount, count[i]);
                }
            }
        }
        return maxCount;
    }
};