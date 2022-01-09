class Solution {
public:
    pair<int, int> move(int dir) {
        switch (dir) {
            case 0:
                return make_pair(0, 1);
            case 1:
                return make_pair(1, 0);
            case 2:
                return make_pair(0, -1);
            case 3:
                return make_pair(-1, 0);
            default:
                return make_pair(0, 0);
        }
    }

    int turn(int dir, char ins) {
        return ins == 'L' ? (dir - 1 + 4) % 4 : (dir + 1) % 4;
    }

    bool isRobotBounded(string instructions) {
        int n = instructions.size();
        int x = 0;
        int y = 0;
        int dir = 0;
        for (int times = 0; times < 4; times++) {
            for (int i = 0; i < n; i++) {
                char c = instructions[i];
                if (c == 'G') {
                    pair<int, int> change = move(dir);
                    x += change.first;
                    y += change.second;
                } else {
                    dir = turn(dir, c);
                }
            }
            if (x == 0 && y == 0) return true;
        }
        return false;
    }
};