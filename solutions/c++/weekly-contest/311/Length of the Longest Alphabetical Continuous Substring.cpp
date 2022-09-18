#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();
        int maxLen = 1;
        int currLen = 1;
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c - s[i - 1] == 1) {
                currLen++;
            } else {
                currLen = 1;
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};