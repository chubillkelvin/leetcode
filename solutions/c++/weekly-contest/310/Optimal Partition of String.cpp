#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int count = 1;
        unordered_map<char, int> mp;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (mp.count(c)) {
                count++;
                mp.clear();
            }
            mp[c] = i;
        }
        return count;
    }
};