#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        vector<int> g;
        vector<int> eq;
        vector<int> s;
        for (int num: nums) {
            if (num == pivot) {
                eq.push_back(num);
            } else if (num > pivot) {
                g.push_back(num);
            } else {
                s.push_back(num);
            }
        }
        vector<int> ans;
        for (int num: s) ans.push_back(num);
        for (int num: eq) ans.push_back(num);
        for (int num: g) ans.push_back(num);
        return ans;
    }
};