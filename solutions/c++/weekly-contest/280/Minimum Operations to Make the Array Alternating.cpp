#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) return 0;
        unordered_map<int, int> oddCount;
        unordered_map<int, int> evenCount;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                oddCount[nums[i]]++;
            } else {
                evenCount[nums[i]]++;
            }
        }
        int maxOdd = -1;
        int maxOdd2 = -1;
        int maxOddCount = 0;
        int maxOddCount2 = 0;
        for (auto p: oddCount) {
            if (p.second >= maxOddCount) {
                maxOdd2 = maxOdd;
                maxOddCount2 = maxOddCount;
                maxOdd = p.first;
                maxOddCount = p.second;
            } else if (p.second >= maxOddCount2) {
                maxOdd2 = p.first;
                maxOddCount2 = p.second;
            }
        }
        int maxEven = -1;
        int maxEven2 = -1;
        int maxEvenCount = 0;
        int maxEvenCount2 = 0;
        for (auto p: evenCount) {
            if (p.second >= maxEvenCount) {
                maxEven2 = maxEven;
                maxEvenCount2 = maxEvenCount;
                maxEven = p.first;
                maxEvenCount = p.second;
            } else if (p.second >= maxEvenCount2) {
                maxEven2 = p.first;
                maxEvenCount2 = p.second;
            }
        }
        if (maxOdd != maxEven) {
            return n - maxOddCount - maxEvenCount;
        } else {
            return n - max(maxOddCount2 + maxEvenCount, maxOddCount + maxEvenCount2);
        }
    }
};