#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumCardPickup(vector<int> &cards) {
        unordered_map<int, vector<int>> pos;
        int n = cards.size();
        for (int i = 0; i < n; i++) {
            int curr = cards[i];
            pos[curr].push_back(i);
        }
        int minPick = n + 1;
        for (auto p: pos) {
            if (p.second.size() > 1) {
                int minDiff = n;
                for (int i = 1; i < p.second.size(); i++) {
                    int prev = p.second[i - 1];
                    int curr = p.second[i];
                    minDiff = min(minDiff, curr - prev + 1);
                }
                minPick = min(minPick, minDiff);
            }
        }
        return minPick == n + 1 ? -1 : minPick;
    }
};