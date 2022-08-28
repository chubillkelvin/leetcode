#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int n = garbage.size();
        vector<int> last(3, 0); // {M, P, G}
        int total = 0;
        for (int i = 0; i < n; i++) {
            string g = garbage[i];
            for (char c: g) {
                total++;
                if (c == 'M') {
                    last[0] = i;
                }
                if (c == 'P') {
                    last[1] = i;
                }
                if (c == 'G') {
                    last[2] = i;
                }
            }
        }
        for (int i = 0; i < 3; i++) {
            int lastPos = last[i];
            for (int j = 0; j < lastPos; j++) {
                total += travel[j];
            }
        }
        return total;
    }
};
