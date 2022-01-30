class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int minX = x, minY = y, maxX = x, maxY = y;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<vector<pair<int, int>>> bfs;
        visited[x][y] = true;
        bfs.push({make_pair(x, y)});
        while(!bfs.empty()) {
            auto curr = bfs.front();
            vector<pair<int, int>> next;
            for(auto pixel: curr) {
                int currX = pixel.first;
                int currY = pixel.second;
                minX = min(minX, currX);
                maxX = max(maxX, currX);
                minY = min(minY, currY);
                maxY = max(maxY, currY);
                if (currX-1 >= 0 && image[currX-1][currY] == '1' && !visited[currX-1][currY]) {
                    next.push_back(make_pair(currX-1, currY));
                    visited[currX-1][currY] = true;
                }
                if (currX+1 < m && image[currX+1][currY] == '1' && !visited[currX+1][currY]) {
                    next.push_back(make_pair(currX+1, currY));
                    visited[currX+1][currY] = true;
                }
                if (currY-1 >= 0 && image[currX][currY-1] == '1' && !visited[currX][currY-1]) {
                    next.push_back(make_pair(currX, currY-1));
                    visited[currX][currY-1] = true;
                }
                if (currY+1 < n && image[currX][currY+1] == '1' && !visited[currX][currY+1]) {
                    next.push_back(make_pair(currX, currY+1));
                    visited[currX][currY+1] = true;
                }
            }
            bfs.pop();
            if(!next.empty()) bfs.push(next);
        }
        return (maxX - minX + 1) * (maxY - minY + 1);
    }
};