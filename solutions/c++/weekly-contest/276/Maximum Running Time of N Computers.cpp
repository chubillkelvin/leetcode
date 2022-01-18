#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int> &batteries) {
        long long time = 0;
        priority_queue<int> b;
        for (int battery: batteries) b.push(battery);
        while (!b.empty()) {
            vector<int> used;
            for (int i = 0; i < n; i++) {
                if (b.empty()) return time;
                used.push_back(b.top());
                b.pop();
            }
            int cycles;
            if (b.size() >= n) {
                cycles = used.back();
            } else {
                cycles = max(used.back() / 2 - 1, 1);
            }
            time += cycles;
            for (auto num: used) if (num - cycles > 0) b.push(num - cycles);
        }
        return time;
    }
};