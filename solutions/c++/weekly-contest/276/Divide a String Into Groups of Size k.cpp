#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> ans;
        string curr = "";
        for (int i = 0; i < n; i++) {
            curr += s[i];
            if (curr.size() == k) {
                ans.push_back(curr);
                curr = "";
            }
        }
        if (!curr.empty()) {
            while (curr.size() < k) {
                curr += fill;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};