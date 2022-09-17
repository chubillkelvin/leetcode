#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
        priority_queue<int> p;
        for (auto player: players) p.push(player);
        priority_queue<int> t;
        for (auto trainer: trainers) t.push(trainer);
        int count = 0;
        while (!t.empty()) {
            auto top = t.top();
            t.pop();
            while (!p.empty() && p.top() > top) p.pop();
            if (p.empty()) break;
            p.pop();
            count++;
        }
        return count;
    }
};