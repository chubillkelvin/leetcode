#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeMessage(string key, string message) {
        int count = 0;
        unordered_map<char, char> mp;
        for (char c: key) {
            if (c != ' ' && mp.count(c) == 0) {
                mp[c] = 'a' + count;
                count++;
            }
        }
        string ans;
        for (char c: message) {
            if (c == ' ') {
                ans += c;
            } else {
                ans += mp[c];
            }
        }
        return ans;
    }
};