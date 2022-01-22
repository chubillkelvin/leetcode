class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        unordered_map<int, bool> checked;
        int start = 0;
        while (!checked[start]) {
            checked[start] = true;
            int total = 0;
            for (int i = 0; i < n; i++) {
                int idx = (start + i) % n;
                total += gas[idx] - cost[idx];
                if (total < 0) {
                    start = (idx + 1) % n;
                    break;
                };
                if (i == n - 1) return start;
            }
        }
        return -1;
    }
};