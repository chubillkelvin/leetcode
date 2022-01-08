#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string capitalizeTitle(string title) {
        int n = title.size();
        string ans = "";
        string temp = "";
        for (int i = 0; i < n; i++) {
            char c = title[i];
            if (c == ' ' || i == n - 1) {
                if (i == n - 1) temp += c;
                if (temp.size() > 2) {
                    for (int j = 0; j < temp.size(); j++) {
                        if (j == 0) {
                            ans += toupper(temp[j]);
                        } else {
                            ans += tolower(temp[j]);
                        }
                    }
                } else {
                    for (char ch: temp) ans += tolower(ch);
                }
                temp = "";
                if (i != n - 1) ans += ' ';

            } else {
                temp += c;
            }
        }
        return ans;
    }
};