class DisjointSet {
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 1);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        int rankX = rank[rootX];
        int rankY = rank[rootY];
        if (rankX < rankY) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            if (rankX == rankY) rank[rootX]++;
        }
    }

    int Find(int x) {
        if (root[x] == x) return x;
        return root[x] = Find(root[x]);
    }

    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    int makeConnected(int n, vector <vector<int>> &connections) {
        int m = connections.size();
        if (n - m > 1) return -1;
        auto ds = new DisjointSet(n);
        for (int i = 0; i < m; i++) {
            auto curr = connections[i];
            ds->Union(curr[0], curr[1]);
        }
        unordered_set<int> group;
        for (int i = 0; i < n; i++) group.insert(ds->Find(i));
        return group.size() - 1;
    }
};