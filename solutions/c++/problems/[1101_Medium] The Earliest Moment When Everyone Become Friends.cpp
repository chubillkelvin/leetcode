class DisjointSet {
    vector<int> root;
    vector<int> rank;
    unordered_set<int> activeRoots;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            root[i] = i;
            activeRoots.insert(i);
        }
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
            activeRoots.erase(rootX);
        } else {
            root[rootY] = rootX;
            activeRoots.erase(rootY);
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int getRootCounts() {
        return activeRoots.size();
    }
};

class Solution {
public:
    int earliestAcq(vector <vector<int>> &logs, int n) {
        sort(logs.begin(), logs.end(), [](auto &log1, auto &log2) {
            return log1[0] < log2[0];
        });
        auto ds = new DisjointSet(n);
        for (auto log: logs) {
            if (!ds->connected(log[1], log[2])) {
                ds->unionSet(log[1], log[2]);
                if (ds->getRootCounts() == 1) return log[0];
            }
        }
        return -1;
    }
};