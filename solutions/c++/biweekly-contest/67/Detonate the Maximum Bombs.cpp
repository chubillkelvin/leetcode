#include <bits/stdc++.h>

using namespace std;

struct Bomb {
    int x, y, range;

    Bomb(int X, int Y, int R) {
        x = X;
        y = Y;
        range = R;
    }
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool canBomb(Bomb *from, Bomb *to) {
    int x1 = from->x;
    int x2 = to->x;
    int y1 = from->y;
    int y2 = to->y;
    int r = from->range;
    if (abs(x1 - x2) > r) return false;
    if (abs(y1 - y2) > r) return false;
    double dist = distance(x1, y1, x2, y2);
    return dist <= r;
}

class Solution {
public:
    int maximumDetonation(vector<vector<int>> &bombs) {
        int n = bombs.size();
        vector<set<int>> bombable = vector<set<int>>(n, set<int>{});
        for (int i = 0; i < n; i++) {
            vector<int> curr = bombs[i];
            auto from = new Bomb(curr[0], curr[1], curr[2]);
            for (int j = i + 1; j < n; j++) {
                vector<int> next = bombs[j];
                auto to = new Bomb(next[0], next[1], next[2]);
                if (canBomb(from, to)) {
                    bombable[i].insert(j);
                }
                if (canBomb(to, from)) {
                    bombable[j].insert(i);
                }
            }
        }
        unsigned long maxSoFar = 1;
        for (int i = 0; i < n; i++) {
            set<int> exploded;
            queue<vector<int>> bfs;
            bfs.push({i});
            exploded.insert(i);
            while (!bfs.empty()) {
                vector<int> currLevel = bfs.front();
                vector<int> nextLevel;
                for (auto currBomb: currLevel) {
                    exploded.insert(currBomb);
                    for (int j: bombable[currBomb]) {
                        if (exploded.count(j) > 0) continue;
                        nextLevel.push_back(j);
                        exploded.insert(j);
                    }
                }
                bfs.pop();
                if (!nextLevel.empty()) bfs.push(nextLevel);
            }
            maxSoFar = max(maxSoFar, exploded.size());
        }
        return maxSoFar;
    }
};