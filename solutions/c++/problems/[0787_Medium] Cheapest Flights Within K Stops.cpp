class Solution {
public:
    int findCheapestPrice(int n, vector <vector<int>> &flights, int src, int dst, int k) {
        vector <vector<int>> cost(n, vector<int>(n, -1));
        for (int i = 0; i < flights.size(); i++) {
            auto f = flights[i];
            cost[f[0]][f[1]] = f[2];
        }
        vector<int> memo(n, -1);
        memo[src] = 0;
        queue <unordered_set<int>> bfs;
        unordered_set<int> next;
        next.insert(src);
        bfs.push(next);
        int count = 0;
        while (!bfs.empty() && count <= k) {
            vector<int> newMemo(memo.begin(), memo.end());
            auto curr = bfs.front();
            unordered_set<int> next;
            for (auto node: curr) {
                for (int i = 0; i < n; i++) {
                    int currCost = cost[node][i];
                    if (currCost < 0) continue;
                    int totalCost = memo[node] + currCost;
                    if (memo[i] == -1 || totalCost < memo[i]) {
                        newMemo[i] = newMemo[i] == -1 ? totalCost : min(newMemo[i], totalCost);
                        next.insert(i);
                    }
                }
            }
            bfs.pop();
            count++;
            memo = newMemo;
            if (!next.empty()) bfs.push(next);
        }
        return memo[dst];
    }
};