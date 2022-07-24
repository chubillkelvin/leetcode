#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> se;
        for (char c: s) {
            if (se.count(c)) return c;
            se.insert(c);
        }
        return s[s.size() - 1];
    }
};