#include <bits/stdc++.h>

using namespace std;

// Memory Limit Exceeded :(
class DisjSet {
    int *rank, *parent, n;

public:
    DisjSet(int n) {
        this->n = n;
        Reset();
    }

    void makeSet() {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void Union(int x, int y) {
        int xset = find(x);
        int yset = find(y);

        if (xset == yset)
            return;

        if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset] = rank[xset] + 1;
        }
    }

    void Reset() {
        rank = new int[this->n];
        parent = new int[this->n];
        makeSet();
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};

bool sortByTime(vector<int> sch1, vector<int> sch2) {
    return sch1[2] < sch2[2];
}

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>> &meetings, int firstPerson) {
        set<int> ans = {0, firstPerson};
        sort(meetings.begin(), meetings.end(), sortByTime);

        DisjSet ds(n);
        for (int i = 0; i < meetings.size(); i++) {
            vector<int> curr = meetings[i];
            int first = curr[0];
            int second = curr[1];
            ds.Union(first, second);
            if (ans.count(first) > 0 || ans.count(second) > 0) {
                ds.Union(first, 0);
                ans.insert(first);
                ans.insert(second);
            } else if (ds.connected(first, 0)) {
                ans.insert(first);
                ans.insert(second);
            }

            vector<int> next = {0, 0, -1};
            if (i < meetings.size() - 1) next = meetings[i + 1];

            if (curr[2] != next[2]) {
                // clear curr data
                ds.Reset();
            }
        }

        return vector<int>(ans.begin(), ans.end());
    }
};