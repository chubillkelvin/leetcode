#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
        unordered_set<int> n1;
        unordered_set<int> n2;
        for (int num: nums1) n1.insert(num);
        for (int num: nums2) n2.insert(num);
        for (int num: nums1) n2.erase(num);
        for (int num: nums2) n1.erase(num);
        vector<int> temp1 = vector<int>(n1.begin(), n1.end());
        vector<int> temp2 = vector<int>(n2.begin(), n2.end());
        return {temp1, temp2};
    }
};