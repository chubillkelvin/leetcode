struct Dist {
    int bike, worker, dist;
    Dist(int bike, int worker, int dist) {
        this->bike = bike;
        this->worker = worker;
        this->dist = dist;
    }
};

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int n = workers.size();
        int m = bikes.size();
        vector<Dist*> dist;
        dist.reserve(m * n);
        for(int i = 0; i < m; i++) {
            auto bike = bikes[i];
            for(int j = 0; j < n; j++) {
                auto worker = workers[j];
                dist.push_back(new Dist(i, j, abs(bike[0]-worker[0]) + abs(bike[1]-worker[1])));
            }
        }
        sort(dist.begin(), dist.end(), [](auto &d1, auto &d2) {
            if (d1->dist < d2->dist) return true;
            if (d1->dist > d2->dist) return false;
            if (d1->worker < d2->worker) return true;
            if (d1->worker > d2->worker) return false;
            return d1->bike < d2->bike;
        });
        int assigned = 0;
        vector<int> w(n, -1);
        vector<bool> b(m, false);
        for(auto &d: dist) {
            if (!b[d->bike] && w[d->worker] == -1) {
                b[d->bike] = true;
                w[d->worker] = d->bike;
                assigned++;
                if (assigned == n) return w;
            }
        }
        return w;
    }
};