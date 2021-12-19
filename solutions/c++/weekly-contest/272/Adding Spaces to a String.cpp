#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addSpaces(string s, vector<int> &spaces) {
        int n = s.size();
        set<int> spaceIndex;
        for (auto space: spaces) spaceIndex.insert(space);
        string ans = "";
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (spaceIndex.count(i) > 0) ans += " ";
            ans += c;
        }
        return ans;
    }
};