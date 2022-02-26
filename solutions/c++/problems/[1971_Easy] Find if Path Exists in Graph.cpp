class DisjointSet {
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) {
            root[i] = i;
        }
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rank[rootX] < rank[rootY]) {
            root[rootX] = rootY;
        } else {
            root[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
    }

    int find(int x) {
        if (x == root[x]) return x;
        return root[x] = find(root[x]);
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
public:
    bool validPath(int n, vector <vector<int>> &edges, int source, int destination) {
        auto ds = DisjointSet(n);
        for (auto edge: edges) ds.unionSet(edge[0], edge[1]);
        return ds.connected(source, destination);
    }
};