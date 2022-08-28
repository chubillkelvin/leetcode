#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeStars(string s) {
        int n = s.size();
        string ans = "";
        int skip = 0;
        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            if (c == '*') {
                skip++;
            } else {
                if (skip == 0) {
                    ans += c;
                } else {
                    skip--;
                }
            }
        }
        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
