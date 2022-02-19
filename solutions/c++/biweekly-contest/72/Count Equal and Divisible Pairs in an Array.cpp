#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, vector<int>> memo;
        for (int i = 0; i < n; i++) {
            memo[nums[i]].push_back(i);
        }
        int count = 0;
        for (auto p: memo) {
            vector<int> numbers = p.second;
            int m = numbers.size();
            for (int i = 0; i < m; i++) {
                int first = numbers[i];
                for (int j = i + 1; j < m; j++) {
                    int second = numbers[j];
                    if ((first * second) % k == 0) count++;
                }
            }
        }
        return count;
    }
};