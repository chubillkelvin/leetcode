#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDistance(vector<int> &colors) {
        int minColor = colors[0];
        int minColor2Index = 9999;
        int maxColorIndex = 0;
        for (int i = 1; i < colors.size(); i++) {
            int color = colors[i];
            if (color != minColor) {
                if (minColor2Index == 9999) {
                    minColor2Index = i;
                }
                maxColorIndex = i;
            }
        }
        int endColor = colors[colors.size() - 1];
        if (endColor == minColor) {
            int sol = colors.size() - 1 - minColor2Index;
            return max(sol, maxColorIndex);
        } else {
            return colors.size() - 1;
        }
    }
};