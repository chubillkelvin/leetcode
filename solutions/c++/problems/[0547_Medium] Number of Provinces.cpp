class DisjointSet {
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void Union(int x, int y) {
        int rootX = Find(x);
        int rootY = Find(y);
        if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
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
    int findCircleNum(vector <vector<int>> &isConnected) {
        int n = isConnected.size();
        auto ds = new DisjointSet(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) ds->Union(i, j);
            }
        }
        vector<int> provinces;
        for (int i = 0; i < n; i++) {
            bool shouldAdd = true;
            for (int root: provinces) {
                if (ds->connected(i, root)) {
                    shouldAdd = false;
                    break;
                }
            }
            if (shouldAdd) provinces.push_back(i);
        }
        return provinces.size();
    }
};