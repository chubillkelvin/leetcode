#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int> &special) {
        std::sort(special.begin(), special.end());
        int start = min(bottom, special[0]);
        int end = max(top, special.back());
        int i = 0;
        int maxCount = 0;
        while (start < end && i < special.size()) {
            int count = special[i] - start;
            maxCount = max(maxCount, count);
            start = special[i] + 1;
            i++;
        }
        if (end > start) maxCount = max(maxCount, end - start + 1);
        return maxCount;
    }
};
