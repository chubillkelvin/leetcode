#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int d = 0;
        stack<char> open = {};
        for (char c: s) {
            if (c == '(') {
                open.push(c);
                int o = open.size();
                d = max(d, o);
            }
            if (c == ')') {
                open.pop();
            }
        }
        return d;
    }
};