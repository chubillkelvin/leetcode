#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        if (nums.size() <= 1) return nums;

        sort(nums.begin(), nums.end());

        vector<vector<int>> allSets = {};
        for (int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            vector<int> maxSetAtCurr = {};
            for (int j = 0; j < i; j++) {
                vector<int> setAtJ = allSets[j];
                int maxNumAtJ = setAtJ[setAtJ.size() - 1];
                if (setAtJ.size() > maxSetAtCurr.size() && curr % maxNumAtJ == 0) {
                    maxSetAtCurr = setAtJ;
                }
            }
            maxSetAtCurr.push_back(curr);
            allSets.push_back(maxSetAtCurr);
        }

        vector<int> largestSet = {};
        for (vector<int> currSet: allSets) {
            if (currSet.size() > largestSet.size()) {
                largestSet = currSet;
            }
        }
        return largestSet;
    }
};