#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        int maxP = 1;
        int p = 1;
        char curr = s[0];
        for (int i = 1; i < n; i++) {
            char c = s[i];
            if (c == curr) {
                p++;
            } else {
                maxP = max(p, maxP);
                p = 1;
                curr = c;
            }
        }
        return max(p, maxP);
    }
};