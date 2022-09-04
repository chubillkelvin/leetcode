#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());
        vector<int> count(n, 0);
        set<int> available;
        for (int i = 0; i < n; i++) available.insert(i);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> q;
        for (auto meeting: meetings) {
            long long start = meeting[0];
            long long end = meeting[1];
            while (!q.empty() && q.top().first <= start) {
                available.insert(q.top().second);
                q.pop();
            }
            if (available.empty()) {
                auto top = q.top();
                int duration = end - start;
                start = top.first;
                end = start + duration;
                available.insert(top.second);
                q.pop();
            }
            auto room = available.begin();
            int roomNum = *room;
            count[roomNum]++;
            available.erase(roomNum);
            q.push({end, roomNum});
        }
        int booked = count[0];
        int mostBooked = 0;
        for (int i = 1; i < n; i++) {
            if (count[i] > booked) {
                booked = count[i];
                mostBooked = i;
            }
        }
        return mostBooked;
    }
};