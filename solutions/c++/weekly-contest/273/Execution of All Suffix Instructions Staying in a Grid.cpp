#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int> &startPos, string s) {
        int inSize = s.size();
        vector<int> ans = vector<int>(inSize, 0);
        for (int i = 0; i < inSize; i++) {
            int count = 0;
            int currX = startPos[1];
            int currY = startPos[0];
            for (int j = i; j < inSize; j++) {
                char currMove = s[j];
                if (currMove == 'L') {
                    currX--;
                }
                if (currMove == 'R') {
                    currX++;
                }
                if (currMove == 'U') {
                    currY--;
                }
                if (currMove == 'D') {
                    currY++;
                }
                if (currX >= 0 && currX < n && currY >= 0 && currY < n) {
                    count++;
                } else {
                    break;
                }
            }
            ans[i] = count;
        }
        return ans;
    }
};