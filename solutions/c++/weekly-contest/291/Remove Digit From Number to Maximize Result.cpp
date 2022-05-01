#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string removeDigit(string number, char digit) {
        int n = number.size();
        vector<int> pos;
        for (int i = 0; i < n; i++) {
            char c = number[i];
            if (c == digit) pos.push_back(i);
        }
        vector<string> ans;
        for (int p: pos) {
            string temp;
            for (int i = 0; i < n; i++) {
                if (i == p)continue;
                temp += number[i];
            }
            ans.push_back(temp);
        }
        std::sort(ans.begin(), ans.end());
        return ans.back();
    }
};