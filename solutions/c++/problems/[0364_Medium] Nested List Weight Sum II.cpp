#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int depthSumInverse(vector<NestedInteger> &nestedList) {
        queue<vector<NestedInteger>> levels;
        levels.push(nestedList);
        vector<int> levelSum;
        while (!levels.empty()) {
            auto currLevel = levels.front();
            int currSum = 0;
            vector<NestedInteger> nextLevel;
            for (auto nestedNum: currLevel) {
                if (nestedNum.isInteger()) {
                    currSum += nestedNum.getInteger();
                } else {
                    for (auto num: nestedNum.getList()) {
                        nextLevel.push_back(num);
                    }
                }
            }
            levelSum.push_back(currSum);
            levels.pop();
            if (!nextLevel.empty()) levels.push(nextLevel);
        }
        int maxDepth = levelSum.size();
        int total = 0;
        for (int i = 0; i < maxDepth; i++) {
            int weight = maxDepth - i;
            total += levelSum[i] * weight;
        }
        return total;
    }
};