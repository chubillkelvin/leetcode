struct Point {
    int x, y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    string toString(int start, int end) {
        return to_string(x - start) + to_string(y - end);
    }
};

class Solution {
public:
    int numDistinctIslands(vector <vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector <vector<int>> visited(m, vector<int>(n, 0));
        set <string> islands;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                if (grid[i][j] == 1) {
                    string result = "";
                    queue <vector<struct Point>> bfs;
                    bfs.push(vector<struct Point>{Point(i, j)});
                    while (!bfs.empty()) {
                        auto curr = bfs.front();
                        vector<struct Point> nextLevel;
                        for (auto pt: curr) {
                            if (pt.x < 0 || pt.x > m - 1) continue;
                            if (pt.y < 0 || pt.y > n - 1) continue;
                            if (grid[pt.x][pt.y] == 0) continue;
                            if (visited[pt.x][pt.y] == 1) continue;
                            visited[pt.x][pt.y] = 1;
                            result += pt.toString(i, j);
                            nextLevel.push_back(Point(pt.x - 1, pt.y));
                            nextLevel.push_back(Point(pt.x, pt.y - 1));
                            nextLevel.push_back(Point(pt.x + 1, pt.y));
                            nextLevel.push_back(Point(pt.x, pt.y + 1));
                        }
                        bfs.pop();
                        if (!nextLevel.empty()) bfs.push(nextLevel);
                    }
                    islands.insert(result);
                }
            }
        }
        return islands.size();
    }
};