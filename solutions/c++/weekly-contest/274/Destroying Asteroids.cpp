#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> &asteroids) {
        int n = asteroids.size();
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for (int i = 0; i < n; i++) {
            int curr = asteroids[i];
            if (m >= curr) {
                m += curr;
            } else {
                return false;
            }
        }
        return true;
    }
};