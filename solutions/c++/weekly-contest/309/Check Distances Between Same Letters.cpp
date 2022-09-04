#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkDistances(string s, vector<int> &distance) {
        int n = s.size();
        unordered_map<char, int> last;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (last.count(c)) {
                if (distance[c - 'a'] + 1 != i - last[c]) return false;
            } else {
                last[c] = i;
            }
        }
        return true;
    }
};