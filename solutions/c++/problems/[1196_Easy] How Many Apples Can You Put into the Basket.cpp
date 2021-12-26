#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxNumberOfApples(vector<int> &weight) {
        int n = weight.size();
        sort(weight.begin(), weight.end());
        int count = 0;
        int cap = 5000;
        for (int i = 0; i < n; i++) {
            int w = weight[i];
            if (w <= cap) {
                cap -= w;
                count++;
            }
        }
        return count;
    }
};