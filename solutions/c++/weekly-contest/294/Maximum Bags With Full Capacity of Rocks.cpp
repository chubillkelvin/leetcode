#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maximumBags(vector<int> &capacity, vector<int> &rocks, int additionalRocks) {
        int n = capacity.size();
        int count = 0;
        vector<int> bags;
        for (int i = 0; i < n; i++) {
            int curr = capacity[i] - rocks[i];
            if (curr == 0) {
                count++;
            } else {
                bags.push_back(curr);
            }
        }
        std::sort(bags.begin(), bags.end());
        int i = 0;
        while (additionalRocks > 0 && i < bags.size()) {
            int curr = bags[i];
            int next = curr - min(curr, additionalRocks);
            additionalRocks -= min(curr, additionalRocks);
            if (next == 0) {
                i++;
                count++;
            }
        }
        return count;
    }
};