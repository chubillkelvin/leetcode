#include <bits/stdc++.h>

using namespace std;

int sum(vector<int> array) {
    int total = 0;
    return accumulate(array.begin(), array.end(), total);
}

class Solution {
public:
    int splitArray(vector<int> &nums, int m) {
        // binary search
        int low = *max_element(nums.begin(), nums.end());
        int high = sum(nums);
        int bestSoFar = high;
        while (low <= high) {
            int mid = (high + low) / 2;
            int count = 1;
            vector<int> sums = {nums[0]};
            for (int i = 1; i < nums.size(); i++) {
                int num = nums[i];
                int prevSum = sums[i - 1];
                if (prevSum + num > mid) {
                    count++;
                    sums.push_back(num);
                } else {
                    sums.push_back(prevSum + num);
                }
            }
            if (count > m) {
                low = mid + 1;
            } else {
                bestSoFar = min(bestSoFar, mid);
                high = mid - 1;
            }
        }
        return bestSoFar;
    }
};