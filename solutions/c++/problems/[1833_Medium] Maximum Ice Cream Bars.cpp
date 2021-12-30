class Solution {
public:
    int maxIceCream(vector<int> &costs, int coins) {
        int n = costs.size();
        sort(costs.begin(), costs.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            int curr = costs[i];
            if (coins >= curr) {
                coins -= curr;
                count++;
            } else {
                return count;
            }
        }
        return count;
    }
};