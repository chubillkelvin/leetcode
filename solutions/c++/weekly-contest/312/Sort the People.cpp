#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights) {
        int n = names.size();
        priority_queue<pair<int, string>> q;
        for (int i = 0; i < n; i++) {
            q.push({heights[i], names[i]});
        }
        vector<string> ans;
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};