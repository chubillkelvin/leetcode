#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<string, int> dp;
public:
    int deleteString(string s) {
        int n = s.size();
        if (n == 1) return 1;
        if (dp.count(s)) return dp[s];
        if (n == 2) return dp[s] = s[0] == s[1] ? 2 : 1;
        if (n == 3) return dp[s] = s[0] == s[1] ? s[1] == s[2] ? 3 : 2 : 1;
        unordered_set<char> chars;
        for (char c: s) chars.insert(c);
        if (chars.size() == 1) return n;
        string temp = "";
        int maxDel = 1;
        for (int i = 0; i <= n / 2; i++) {
            temp += s[i];
            if (temp == s.substr(i + 1, temp.size())) {
                maxDel = max(maxDel, 1 + deleteString(s.substr(i + 1, n - temp.size())));
            }
        }
        return dp[s] = maxDel;
    }
};