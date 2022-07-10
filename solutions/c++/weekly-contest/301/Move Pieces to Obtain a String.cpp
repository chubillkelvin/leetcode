#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.size();
        vector<pair<int, char>> s;
        for (int i = 0; i < n; i++) {
            char c = start[i];
            if (c != '_') {
                s.push_back({i, c});
            }
        }
        vector<pair<int, char>> e;
        for (int i = 0; i < n; i++) {
            char c = target[i];
            if (c != '_') {
                e.push_back({i, c});
            }
        }
        if (s.size() != e.size()) return false;
        for (int i = 0; i < s.size(); i++) {
            auto p1 = s[i];
            auto p2 = e[i];
            if (p1.second != p2.second) return false;
            if (p1.second == 'L' && p1.first < p2.first) return false;
            if (p1.second == 'R' && p1.first > p2.first) return false;
        }
        return true;
    }
};