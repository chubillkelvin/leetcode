#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int percentageLetter(string s, char letter) {
        int n = s.size();
        unordered_map<char, int> mp;
        for (char c: s) mp[c]++;
        return mp[letter] * 100 / n;
    }
};