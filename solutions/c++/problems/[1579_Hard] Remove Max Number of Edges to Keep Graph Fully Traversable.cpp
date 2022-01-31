class DisjointSet {
    vector<int> root;
    vector<int> rank;
    unordered_set<int> connectedNodes;
    unordered_set<int> activeRoots;
public:
    DisjointSet(int n) {
        root.reserve(n);
        rank = vector<int>(n, 0);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void unionSet(int x, int y) {
        connectedNodes.insert(x);
        connectedNodes.insert(y);
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

    bool allConnected(int n) {
        if (connectedNodes.size() == n && activeRoots.size() == 1) return true;
        return false;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector <vector<int>> &edges) {
        auto alice = new DisjointSet(n + 1);
        auto bob = new DisjointSet(n + 1);
        sort(edges.begin(), edges.end(), [](auto &e1, auto &e2) {
            return e1[0] > e2[0];
        });
        int edgeCount = 0;
        for (auto edge: edges) {
            if (edge[0] == 3) {
                if (!alice->connected(edge[1], edge[2])) {
                    alice->unionSet(edge[1], edge[2]);
                    bob->unionSet(edge[1], edge[2]);
                    edgeCount++;
                }
            } else if (edge[0] == 2) {
                if (!bob->connected(edge[1], edge[2])) {
                    bob->unionSet(edge[1], edge[2]);
                    edgeCount++;
                }
            } else {
                if (!alice->connected(edge[1], edge[2])) {
                    alice->unionSet(edge[1], edge[2]);
                    edgeCount++;
                }
            }
            if (alice->allConnected(n) && bob->allConnected(n)) return edges.size() - edgeCount;
        }
        if (!alice->allConnected(n)) return -1;
        if (!bob->allConnected(n)) return -1;
        return edges.size() - edgeCount;
    }
};