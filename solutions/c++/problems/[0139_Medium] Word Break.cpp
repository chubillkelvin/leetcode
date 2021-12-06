#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool startsWith(string a, string b) {
        if (b.size() > a.size()) return false;
        for (int i = 0; i < b.size(); i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }

    bool wordBreak(string s, vector<string> &wordDict) {
        int n = s.size();
        vector<bool> ans = vector<bool>(n + 1, false);
        // base case
        ans[n] = true;
        for (int i = n - 1; i >= 0; i--) {
            string curr = s.substr(i, n - i);
            for (string word: wordDict) {
                if (startsWith(curr, word)) {
                    ans[i] = ans[i + word.size()] || ans[i];
                }
            }
        }
        return ans[0];
    }
};