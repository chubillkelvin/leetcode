#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkString(string s) {
        bool hasB = false;
        for (char c: s) {
            if (c == 'b') hasB = true;
            if (hasB && c == 'a') return false;
        }
        return true;
    }
};