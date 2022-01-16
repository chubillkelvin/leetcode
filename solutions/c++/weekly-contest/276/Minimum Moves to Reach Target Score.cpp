#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while (maxDoubles > 0 && target > 1) {
            if (target % 2 == 1) {
                target--;
                moves++;
            } else {
                target /= 2;
                moves++;
                maxDoubles--;
            }
        }
        if (target > 1) {
            moves += target - 1;
        }
        return moves;
    }
};