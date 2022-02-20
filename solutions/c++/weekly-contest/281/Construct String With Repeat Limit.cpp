#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.size();
        vector<int> count(26, 0);
        for (char c: s) count[c - 'a']++;
        priority_queue<pair<char, int>> q;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) q.push(make_pair('a' + i, count[i]));
        }
        string ans = "";
        while (!q.empty()) {
            vector<pair<char, int>> temp;
            auto top = q.top();
            q.pop();
            if (top.first == ans.back()) {
                temp.push_back(top);
                if (q.empty()) {
                    return ans;
                } else {
                    top = q.top();
                    q.pop();
                }
            }
            if (!temp.empty()) {
                ans += top.first;
                if (top.second - 1 > 0) q.push(make_pair(top.first, top.second - 1));
            } else {
                int times = min(repeatLimit, top.second);
                for (int i = 0; i < times; i++) ans += top.first;
                if (top.second - times > 0) q.push(make_pair(top.first, top.second - times));
            }
            for (auto p: temp) q.push(p);
        }
        return ans;
    }
};