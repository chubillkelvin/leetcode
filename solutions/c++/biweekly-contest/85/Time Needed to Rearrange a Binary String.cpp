#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int n = s.size();
        vector<int> zeroPos;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '0') {
                zeroPos.push_back(i);
            }
        }
        int m = zeroPos.size();
        int count = 0;
        do {
            bool update = false;
            vector<int> zPos;
            for (int i = 0; i < m; i++) {
                int curr = zeroPos[i];
                if (i == m - 1) {
                    if (curr == n - 1) {
                        zPos.push_back(curr);
                    } else {
                        zPos.push_back(curr + 1);
                        update = true;
                    }
                } else {
                    int next = zeroPos[i + 1];
                    if (curr + 1 == next) {
                        zPos.push_back(curr);
                    } else {
                        zPos.push_back(curr + 1);
                        update = true;
                    }
                }
            }
            if (!update) break;
            zeroPos = zPos;
            count++;
        } while (true);
        return count;
    }
};