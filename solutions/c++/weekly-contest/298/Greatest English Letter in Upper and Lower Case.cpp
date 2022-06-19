#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string greatestLetter(string s) {
        unordered_map<char, bool> lower;
        unordered_map<char, bool> upper;
        for (char c: s) {
            if (c - 'a' >= 0 && c - 'a' < 26) {
                lower[c] = true;
            } else {
                upper[c] = true;
            }
        }
        for (int i = 25; i >= 0; i--) {
            char curr = 'A' + i;
            if (upper[curr] && lower['a' + i]) {
                string ans;
                ans += curr;
                return ans;
            }
        }
        return "";
    }
};