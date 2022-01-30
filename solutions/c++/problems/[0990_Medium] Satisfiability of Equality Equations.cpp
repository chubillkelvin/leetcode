class DisjointSet {
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet() {
        root.reserve(26);
        rank = vector<int>(26, 1);
        for (int i = 0; i < 26; i++) root[i] = i;
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
    bool equationsPossible(vector <string> &equations) {
        int n = equations.size();
        auto ds = new DisjointSet();
        for (int i = 0; i < n; i++) {
            string curr = equations[i];
            if (curr[1] == '=') {
                int x = curr[0] - 'a';
                int y = curr[3] - 'a';
                ds->Union(x, y);
            }
        }
        for (int i = 0; i < n; i++) {
            string curr = equations[i];
            if (curr[1] == '!') {
                int x = curr[0] - 'a';
                int y = curr[3] - 'a';
                if (ds->connected(x, y)) return false;
            }
        }
        return true;
    }
};