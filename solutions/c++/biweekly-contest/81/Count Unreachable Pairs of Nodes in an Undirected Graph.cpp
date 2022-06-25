#include <bits/stdc++.h>

using namespace std;

class DisjointSet {
    int n;
    vector<int> root;
    vector<int> rank;
public:
    DisjointSet(int n) {
        this->n = n;
        rank = vector<int>(n, 1);
        root.reserve(n);
        for (int i = 0; i < n; i++) root[i] = i;
    }

    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;
        if (rank[rootX] >= rank[rootY]) {
            root[rootY] = rootX;
            if (rank[rootX] == rank[rootY]) rank[rootX]++;
        } else {
            root[rootX] = rootY;
        }
    }

    int find(int x) {
        int rootX = root[x];
        if (rootX == x) return x;
        return root[x] = find(rootX);
    }

    long long count() {
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[find(i)]++;
        }
        long long total = 0;
        for (auto p: mp) total += p.second;
        long long count = 0;
        for (int i = 0; i < n; i++) {
            count += (total - mp[find(i)]);
            total--;
            mp[find(i)]--;
        }
        return count;
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>> &edges) {
        auto ds = new DisjointSet(n);
        for (auto e: edges) {
            ds->join(e[0], e[1]);
        }
        return ds->count();
    }
};