class DisjointSet {
    vector<int> root;
    vector<int> rank;
    unordered_set<int> activeRoot;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        activeRoot.insert(rootX);
        activeRoot.insert(rootY);
        if (rank[rootX] < rank[rootY]) {
            if (rootX != rootY) activeRoot.erase(rootX);
            root[rootX] = rootY;
        } else {
            if (rootX != rootY) activeRoot.erase(rootY);
            root[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        }
    }

    int find(int x) {
        if (root[x] == x) return x;
        return root[x] = find(root[x]);
    }

    int rootCount() {
        return activeRoot.size();
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

class Solution {
    int m, n;
public:
    int index(int row, int col) {
        return row * n + col;
    }

    vector<int> numIslands2(int m, int n, vector <vector<int>> &positions) {
        this->m = m;
        this->n = n;
        auto ds = new DisjointSet(m * n);
        unordered_set<int> landIndex;
        vector<int> count;
        for (int i = 0; i < positions.size(); i++) {
            auto p = positions[i];
            int row = p[0];
            int col = p[1];
            int curr = index(row, col);
            landIndex.insert(curr);
            ds->unionSet(curr, curr);
            if (row - 1 >= 0 && landIndex.count(index(row - 1, col)) > 0) ds->unionSet(curr, index(row - 1, col));
            if (row + 1 < m && landIndex.count(index(row + 1, col)) > 0) ds->unionSet(curr, index(row + 1, col));
            if (col - 1 >= 0 && landIndex.count(index(row, col - 1)) > 0) ds->unionSet(curr, index(row, col - 1));
            if (col + 1 < n && landIndex.count(index(row, col + 1)) > 0) ds->unionSet(curr, index(row, col + 1));
            count.push_back(ds->rootCount());
        }
        return count;
    }
};