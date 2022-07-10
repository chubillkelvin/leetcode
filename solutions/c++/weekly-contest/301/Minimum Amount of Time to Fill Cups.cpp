#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int fillCups(vector<int> &amount) {
        priority_queue<int> q;
        for (int num: amount) if (num != 0) q.push(num);
        int time = 0;
        while (!q.empty()) {
            auto top = q.top();
            q.pop();
            if (!q.empty()) {
                auto top2 = q.top();
                q.pop();
                if (top2 > 1) q.push(top2 - 1);
            }
            if (top > 1) q.push(top - 1);
            time++;
        }
        return time;
    }
};