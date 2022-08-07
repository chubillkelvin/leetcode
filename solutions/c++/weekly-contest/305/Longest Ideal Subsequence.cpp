#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.size();
        vector<int> maxCount(26, 0);
        int count = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int ci = c - 'a';
            int prevCount = 0;
            for (int j = 0; j <= k; j++) {
                if (ci + j < 26) {
                    prevCount = max(prevCount, maxCount[ci + j]);
                }
                if (ci - j >= 0) {
                    prevCount = max(prevCount, maxCount[ci - j]);
                }
            }
            maxCount[ci] = prevCount + 1;
            count = max(count, maxCount[ci]);
        }
        return count;
    }
};
