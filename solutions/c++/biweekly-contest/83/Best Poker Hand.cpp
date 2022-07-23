#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        unordered_map<char, int> c;
        unordered_map<int, int> r;
        for (int i = 0; i < 5; i++) {
            c[suits[i]]++;
            r[ranks[i]]++;
        }
        if (c.size() == 1) return "Flush";
        for (auto p: r) {
            if (p.second >= 3) return "Three of a Kind";
        }
        for (auto p: r) {
            if (p.second >= 2) return "Pair";
        }
        return "High Card";
    }
};