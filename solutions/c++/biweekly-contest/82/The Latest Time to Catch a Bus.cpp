#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        std::sort(buses.begin(), buses.end());
        priority_queue<int, vector<int>, greater<>> q;
        unordered_map<int, bool> memo;
        for (auto p: passengers) q.push(p);
        int latest = 1;
        for (int i = 0; i < buses.size(); i++) {
            int bus = buses[i];
            int temp = capacity;
            while (temp > 0 && !q.empty() && q.top() <= bus) {
                memo[q.top()] = true;
                if (!memo[q.top() - 1]) latest = max(latest, q.top() - 1);
                q.pop();
                temp--;
            }
            if (temp > 0 && !memo[bus]) latest = max(latest, bus);
        }
        return latest;
    }
};