#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        if (height.size() == 0)
            return 0;
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        int maxArea = 0;

        do {
            int leftValue = height[leftIndex];
            int rightValue = height[rightIndex];
            maxArea = max(maxArea, getArea(leftIndex, leftValue, rightIndex, rightValue));
            if (leftValue > rightValue)
                rightIndex--;
            else
                leftIndex++;

        } while (leftIndex != rightIndex);

        return maxArea;
    }

    int getArea(int leftIndex, int leftValue, int rightIndex, int rightValue) {
        return (rightIndex - leftIndex) * min(leftValue, rightValue);
    }
};
