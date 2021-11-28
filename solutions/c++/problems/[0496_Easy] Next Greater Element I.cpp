#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        stack<int> s = {};
        s.push(nums2[0]);
        map<int, int> indexMap = {};
        vector<int> g = vector<int>(nums2.size(), -1);
        for (int i = 1; i < nums2.size(); i++) {
            int num = nums2[i];
            indexMap[num] = i;

            while (!s.empty() && num > s.top()) {
                int value = s.top();
                g[indexMap[value]] = num;
                s.pop();
            }

            s.push(num);
        }

        vector<int> ans = {};
        for (int num: nums1) {
            ans.push_back(g[indexMap[num]]);
        }
        return ans;
    }
};
