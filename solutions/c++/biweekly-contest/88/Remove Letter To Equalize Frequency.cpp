#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool equalFrequency(string word) {
        vector<int> count(26, 0);
        for (char c: word) count[c - 'a']++;
        map<int, int> counts;
        for (int num: count) {
            if (num == 0) continue;
            counts[num]++;
        }
        if (counts.size() > 2) return false;
        if (counts.size() == 1) {
            if (counts.begin()->first == 1) return true;
            if (counts.begin()->second == 1) return true;
            return false;
        }
        auto low = counts.begin();
        auto hi = counts.rbegin();
        if (low->first == 1 && low->second == 1) return true;
        if (hi->first - low->first > 1) return false;
        if (hi->second == 1) return true;
        return false;
    }
};