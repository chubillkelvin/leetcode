#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        stack<char> open = {};
        stack<char> star = {};
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(') open.push(i);
            if (c == '*') star.push(i);
            if (c == ')') {
                if (open.size() > 0) {
                    open.pop();
                } else if (star.size() > 0) {
                    star.pop();
                } else {
                    return false;
                }
            }
        }

        while (!open.empty() && !star.empty()) {
            char o = open.top();
            char st = star.top();
            if (o > st) return false;
            open.pop();
            star.pop();
        }
        return open.size() == 0;
    }
};
