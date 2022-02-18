class Solution {
    int n, threshold;
public:
    int findMin(vector<int> &dist, vector<bool> &spt) {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (!spt[i] && dist[i] < minDist && dist[i] <= threshold) {
                minDist = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int findTheCity(int n, vector <vector<int>> &edges, int distanceThreshold) {
        this->n = n;
        threshold = distanceThreshold;
        vector <vector<int>> adj(n, vector<int>(n, -1));
        for (auto edge: edges) {
            adj[edge[0]][edge[1]] = edge[2];
            adj[edge[1]][edge[0]] = edge[2];
        }

        int minCities = n;
        int minIndex = 0;
        for (int i = 0; i < n; i++) {
            vector<bool> spt(n, false);
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            int cities = 0;
            for (int j = 0; j < n; j++) {
                int index = findMin(dist, spt);
                if (index == -1) break;
                cities++;
                spt[index] = true;
                for (int k = 0; k < n; k++) {
                    if (spt[k] || adj[index][k] == -1) continue;
                    dist[k] = min(dist[k], dist[index] + adj[index][k]);
                }
            }
            if (cities <= minCities) {
                minCities = cities;
                minIndex = i;
            }
        }
        return minIndex;
    }
};