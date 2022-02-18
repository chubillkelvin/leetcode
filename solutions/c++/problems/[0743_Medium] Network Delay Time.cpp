class Solution {
    int n;
public:
    int findMin(vector<int> &dist, vector<bool> &spt) {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!spt[i] && dist[i] < minDist) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int networkDelayTime(vector <vector<int>> &times, int n, int k) {
        this->n = n;
        vector <vector<int>> adj(n, vector<int>(n, -1));
        for (auto time: times) adj[time[0] - 1][time[1] - 1] = time[2];
        vector<int> dist(n, INT_MAX);
        vector<bool> spt(n, false);
        dist[k - 1] = 0;
        for (int i = 0; i < n - 1; i++) {
            int idx = findMin(dist, spt);
            if (idx == -1) return -1;
            spt[idx] = true;
            for (int j = 0; j < n; j++) {
                if (spt[j] || adj[idx][j] == -1) continue;
                dist[j] = min(dist[j], dist[idx] + adj[idx][j]);
            }
        }
        int maxTime = 0;
        for (auto d: dist) {
            if (d == INT_MAX) return -1;
            maxTime = max(maxTime, d);
        }
        return maxTime;
    }
};