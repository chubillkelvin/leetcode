#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<vector<int>> &arrays) {
        int n = arrays.size();

        // {value, index of array}
        vector<int> min1, min2, max1, max2;
        if (arrays[0].front() <= arrays[1].front()) {
            min1 = {arrays[0].front(), 0};
            min2 = {arrays[1].front(), 1};
        } else {
            min1 = {arrays[1].front(), 1};
            min2 = {arrays[0].front(), 0};
        }

        if (arrays[0].back() >= arrays[1].back()) {
            max1 = {arrays[0].back(), 0};
            max2 = {arrays[1].back(), 1};
        } else {
            max1 = {arrays[1].back(), 1};
            max2 = {arrays[0].back(), 0};

        }
        for (int i = 0; i < n; i++) {
            auto arr = arrays[i];
            int minimum = arr.front();
            int maximum = arr.back();
            if (minimum <= min1[0] && i != min1[1]) {
                min2 = {min1[0], min1[1]};
                min1 = {minimum, i};
            } else if (minimum <= min2[0] && i != min1[1] && i != min2[1]) {
                min2 = {minimum, i};
            }
            if (maximum >= max1[0] && i != max1[1]) {
                max2 = {max1[0], max1[1]};
                max1 = {maximum, i};
            } else if (maximum >= max2[0] && i != max1[1] && i != max2[1]) {
                max2 = {maximum, i};
            }
        }
        
        if (max1[1] == min1[1]) {
            if (max2[0] - min1[0] >= max1[0] - min2[0] && max2[1] != min1[1]) {
                return max2[0] - min1[0];
            } else if (max1[1] != min2[1]) {
                return max1[0] - min2[0];
            } else {
                return max2[0] - min2[0];
            }
        } else {
            return max1[0] - min1[0];
        }
    }
};