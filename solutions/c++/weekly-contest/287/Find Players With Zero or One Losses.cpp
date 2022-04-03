#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        vector<int> count(100001, -1);
        for (auto match: matches) {
            int win = match[0];
            int lose = match[1];
            if (count[win] == -1) count[win] = 0;
            if (count[lose] == -1) count[lose] = 0;
            count[lose]++;
        }
        vector<int> winner;
        vector<int> loser;
        for (int i = 1; i <= 100000; i++) {
            if (count[i] == 0) {
                winner.push_back(i);
            } else if (count[i] == 1) {
                loser.push_back(i);
            }
        }
        return {winner, loser};
    }
};