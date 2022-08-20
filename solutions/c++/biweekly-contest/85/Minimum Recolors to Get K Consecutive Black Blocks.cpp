#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int bCount = 0;
        int wCount = 0;
        int ans = n;
        for (int i = 0; i < n; i++) {
            char c = blocks[i];
            if (c == 'B') {
                bCount++;
            } else {
                wCount++;
            }
            if (bCount + wCount == k) {
                ans = min(ans, wCount);
                if (blocks[i - k + 1] == 'B') {
                    bCount--;
                } else {
                    wCount--;
                }
            }
        }
        return ans;
    }
};