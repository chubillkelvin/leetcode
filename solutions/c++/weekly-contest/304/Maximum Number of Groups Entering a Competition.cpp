#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumGroups(vector<int> &grades) {
        priority_queue<int, vector<int>, greater<>> q;
        for (int g: grades) q.push(g);
        int count = 0;
        while (!q.empty()) {
            if (q.size() < count + 1) break;
            for (int i = 0; i <= count; i++) q.pop();
            count++;
        }
        return count;
    }
};