#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int commonFactors(int a, int b) {
        int count = 0;
        unordered_map<int, bool> fact;
        for (int i = 1; i <= a; i++) if (a % i == 0) fact[i] = true;
        for (int i = 1; i <= b; i++) if (b % i == 0 && fact[i]) count++;
        return count;
    }
};