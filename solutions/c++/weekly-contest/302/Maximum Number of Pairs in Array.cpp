#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> numberOfPairs(vector<int> &nums) {
        int pairs = 0;
        unordered_set<int> numbers;
        for (int num: nums) {
            if (numbers.count(num) > 0) {
                numbers.erase(num);
                pairs++;
            } else {
                numbers.insert(num);
            }
        }
        return {pairs, (int) numbers.size()};
    }
};