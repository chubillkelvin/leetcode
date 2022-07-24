#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long countExcellentPairs(vector<int> &nums, int k) {
        unordered_set<int> numbers(nums.begin(), nums.end());
        int n = numbers.size();
        vector<int> v;
        for (int num: numbers) v.push_back(bitset<32>(num).count());
        std::sort(v.begin(), v.end());
        long long count = 0;
        for (int i = 0; i < n; i++) {
            int curr = v[i];
            auto lb = lower_bound(v.begin(), v.end(), k - curr);
            if (lb != v.end()) {
                count += v.size() - (lb - v.begin());
            }
        }
        return count;
    }
};