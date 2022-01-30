class DisjointSet {
    vector<int> root;
public:
    DisjointSet(int n) {
        root.reserve(n);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        root[rootY] = rootX;
    }

    int Find(int x) {
        if (root[x] == x) return x;
        return root[x] = root[root[x]];
    }

    bool connected(int x, int y) {
        return Find(x) == Find(y);
    }
};

class Solution {
public:
    bool validTree(int n, vector <vector<int>> &edges) {
        auto ds = new DisjointSet(n);
        for (auto edge: edges) {
            if (!ds->connected(edge[0], edge[1])) {
                ds->Union(edge[0], edge[1]);
            } else {
                return false;
            }
        }
        for (int i = 1; i < n; i++) {
            if (!ds->connected(0, i)) return false;
        }
        return true;
    }
};