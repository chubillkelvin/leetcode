#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;

class Solution {
public:
    int numberOfWays(string corridor) {
        long long s = 0;
        long long currS = 0;
        long long currP = 1;
        long long total = 1;
        for (char c: corridor) {
            if (c == 'S') {
                s = (s + 1) % MOD;
                if (currS == 2) {
                    total = (total * currP) % MOD;
                    currP = 1;
                    currS = 1;
                } else {
                    currS++;
                }
            } else if (currS == 2) {
                currP++;
            }
            cout << "currS: " << currS << ", currP: " << currP << endl;
        }
        cout << "s: " << s << ", total: " << total << endl;
        return s > 0 && s % 2 == 0 ? total : 0;
    }
};