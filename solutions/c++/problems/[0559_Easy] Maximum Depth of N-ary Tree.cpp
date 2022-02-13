#include <bits/stdc++.h>

using namespace std;

bool isOpen(char c) {
    return c == '(' || c == '{' || c == '[';
}

class Solution {
public:
    bool isValid(string s) {
        stack<char> open = {};
        for (char c: s) {
            if (isOpen(c)) {
                open.push(c);
            } else {
                if (open.size() == 0) return false;
                char top = open.top();
                if (c == ')' && top != '(') return false;
                if (c == ']' && top != '[') return false;
                if (c == '}' && top != '{') return false;
                open.pop();
            }
        }
        return open.size() == 0;
    }
};