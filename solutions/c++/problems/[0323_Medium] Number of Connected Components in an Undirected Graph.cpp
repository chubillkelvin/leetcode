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
        activeRoots.insert(rootX);
        activeRoots.insert(rootY);
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

    int getRootCount() {
        return activeRoots.size();
    }
};

class Solution {
public:
    int countComponents(int n, vector <vector<int>> &edges) {
        auto ds = new DisjointSet(n);
        for (auto edge: edges) if (!ds->connected(edge[0], edge[1])) ds->unionSet(edge[0], edge[1]);
        return ds->getRootCount();
    }
};