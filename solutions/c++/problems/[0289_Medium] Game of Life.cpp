class Solution {
    int m, n;
    vector <vector<int>> board;
public:
    int neighborLiveCount(int i, int j) {
        int count = 0;
        if (i - 1 >= 0) {
            if (j - 1 >= 0 && board[i - 1][j - 1] == 1) count++;
            if (board[i - 1][j] == 1) count++;
            if (j + 1 < n && board[i - 1][j + 1] == 1) count++;
        }
        if (j - 1 >= 0 && board[i][j - 1] == 1) count++;
        if (j + 1 < n && board[i][j + 1] == 1) count++;
        if (i + 1 < m) {
            if (j - 1 >= 0 && board[i + 1][j - 1] == 1) count++;
            if (board[i + 1][j] == 1) count++;
            if (j + 1 < n && board[i + 1][j + 1] == 1) count++;
        }
        return count;
    }

    void gameOfLife(vector <vector<int>> &board) {
        this->board = board;
        m = board.size();
        n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int count = neighborLiveCount(i, j);
                if (count < 2 || count > 3) {
                    board[i][j] = 0;
                } else if (count == 3) {
                    board[i][j] = 1;
                }
            }
        }
    }
};