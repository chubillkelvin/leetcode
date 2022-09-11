#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minGroups(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        multiset<int> q;
        for (auto curr: intervals) {
            auto ub = q.upper_bound(-curr[0]);
            if (ub != q.end()) {
                q.erase(ub);
            }
            q.insert(-curr[1]);
        }
        return q.size();
    }
};