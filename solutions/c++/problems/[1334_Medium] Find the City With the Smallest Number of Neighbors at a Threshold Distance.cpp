class Solution {
    int n, threshold;
public:
    int findMin(vector<int> &dist, unordered_set<int> &mst) {
        int minDist = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (mst.count(i) == 0 && dist[i] < minDist && dist[i] <= threshold) {
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
            unordered_set<int> mst;
            vector<int> dist(n, INT_MAX);
            dist[i] = 0;
            int cities = 0;
            for (int j = 0; j < n; j++) {
                int index = findMin(dist, mst);
                if (index == -1) break;
                cities++;
                mst.insert(index);
                for (int k = 0; k < n; k++) {
                    if (mst.count(k) > 0) continue;
                    int edge = adj[index][k];
                    if (edge > -1) dist[k] = min(dist[k], dist[index] + edge);
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