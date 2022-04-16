#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        if (cost1 < cost2) swap(cost1, cost2);
        long long count = 0;
        int n = total / cost1;
        for (int i = 0; i <= n; i++) {
            count += (total - cost1 * i) / cost2 + 1;
        }
        return count;
    }
};