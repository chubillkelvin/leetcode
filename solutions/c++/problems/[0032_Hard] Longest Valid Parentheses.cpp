#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() < 2) return 0;

        vector<int> ans = vector<int>(s.size(), 0);
        // base case
        ans[0] = 0;
        ans[1] = s[0] == '(' && s[1] == ')' ? 2 : 0;
        int maxSoFar = ans[1];
        for (int i = 2; i < s.length(); i++) {
            char prev = s[i - 1];
            char curr = s[i];
            if (curr == ')') {
                if (prev == '(') {
                    ans[i] = ans[i - 2] + 2;
                } else if (i - ans[i - 1] > 0 && s[i - ans[i - 1] - 1] == '(') {
                    ans[i] = ans[i - 1] + (i - ans[i - 1] >= 2 ? ans[i - ans[i - 1] - 2] : 0) + 2;
                }
                maxSoFar = max(maxSoFar, ans[i]);
            }
        }
        return max(maxSoFar, ans[s.length() - 1]);
    }
};
