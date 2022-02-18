class Solution {
    int n;
public:
    int findMin(vector<int> &dist, unordered_set<int> &mst) {
        int minVal = INT_MAX;
        int minIndex = -1;
        for (int i = 0; i < n; i++) {
            if (mst.count(i) == 0 && dist[i] < minVal) {
                minVal = dist[i];
                minIndex = i;
            }
        }
        return minIndex;
    }

    int networkDelayTime(vector <vector<int>> &times, int n, int k) {
        this->n = n;
        vector<int> dist(n, INT_MAX);
        unordered_set<int> mst;
        dist[k - 1] = 0;
        int maxTime = 0;
        for (int i = 0; i < n; i++) {
            int index = findMin(dist, mst);
            if (index == -1) return -1;
            mst.insert(index);
            if (i < n - 1) {
                for (int j = 0; j < times.size(); j++) {
                    int from = times[j][0] - 1;
                    int to = times[j][1] - 1;
                    int distance = times[j][2];
                    if (mst.count(from) > 0 && mst.count(to) == 0) {
                        dist[to] = min(dist[to], dist[from] + distance);
                    }
                }
            } else {
                maxTime = dist[index];
            }
        }
        return maxTime;
    }
};