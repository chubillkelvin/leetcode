#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long taskSchedulerII(vector<int> &tasks, int space) {
        int n = tasks.size();
        long long day = 0;
        unordered_map<int, long long> last;
        for (int i = 0; i < n; i++) {
            day++;
            int curr = tasks[i];
            if (last.count(curr)) {
                if (day - last[curr] <= space) {
                    day = (long long) last[curr] + (long long) space + 1;
                }
            }
            last[curr] = day;
        }
        return day;
    }
};