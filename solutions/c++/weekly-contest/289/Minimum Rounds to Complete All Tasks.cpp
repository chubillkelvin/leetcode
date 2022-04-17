#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRounds(vector<int> &tasks) {
        unordered_map<int, int> counts;
        for (int task: tasks) counts[task]++;
        int rounds = 0;
        for (auto p: counts) {
            if (p.second % 3 == 0) {
                rounds += p.second / 3;
            } else if (p.second % 3 == 2) {
                rounds += p.second / 3 + 1;
            } else if (p.second >= 4 && (p.second - 4) % 3 == 0) {
                rounds += (p.second - 4) / 3 + 2;
            } else {
                return -1;
            }
        }
        return rounds;
    }
};