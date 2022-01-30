class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (visited[i][j]) continue;
                visited[i][j] = true;
                if (grid[i][j] == '1') {
                    islands++;
                    queue<vector<pair<int, int>>> bfs;
                    bfs.push({make_pair(i, j)});
                    while(!bfs.empty()) {
                        auto curr = bfs.front();
                        vector<pair<int, int>> next;
                        for(auto point: curr) {
                            int row = point.first;
                            int col = point.second;
                            if (row-1 >= 0 && !visited[row-1][col] && grid[row-1][col] == '1') {
                                visited[row-1][col] = true;
                                next.push_back(make_pair(row-1, col));
                            }
                            if (row+1 < m && !visited[row+1][col] && grid[row+1][col] == '1') {
                                visited[row+1][col] = true;
                                next.push_back(make_pair(row+1, col));
                            }
                            if (col-1 >= 0 && !visited[row][col-1] && grid[row][col-1] == '1') {
                                visited[row][col-1] = true;
                                next.push_back(make_pair(row, col-1));
                            }
                            if (col+1 < n && !visited[row][col+1] && grid[row][col+1] == '1') {
                                visited[row][col+1] = true;
                                next.push_back(make_pair(row, col+1));
                            }
                        }
                        bfs.pop();
                        if(!next.empty())bfs.push(next);
                    }
                }
            }
        }
        return islands;
    }
};