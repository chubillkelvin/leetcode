#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPoints(string rings) {
        int n = rings.size();
        map<char, set<char>> rods;
        for (int i = 0; i < n; i += 2) {
            char color = rings[i];
            char num = rings[i + 1];
            rods[num].insert(color);
        }
        int count = 0;
        for (auto rod: rods) {
            if (rod.second.size() == 3) count++;
        }
        return count;
    }
};