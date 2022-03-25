class Solution {
public:
    int twoCitySchedCost(vector <vector<int>> &costs) {
        int n = costs.size() / 2;
        sort(costs.begin(), costs.end(), [](auto &c1, auto &c2) {
            return c1[0] - c1[1] < c2[0] - c2[1];
        });
        int total = 0;
        for (int i = 0; i < n; i++) total += costs[i][0] + costs[n + i][1];
        return total;
    }
};