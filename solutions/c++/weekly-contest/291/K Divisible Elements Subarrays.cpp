#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countDistinct(vector<int> &nums, int k, int p) {
        int n = nums.size();
        vector<int> prefix(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                prefix[i] = nums[i] % p == 0 ? 1 : 0;
            } else {
                prefix[i] = prefix[i - 1] + (nums[i] % p == 0 ? 1 : 0);
            }
        }
        unordered_set<string> s;
        for (int i = 0; i < n; i++) {
            int end = i;
            while (end < n - 1) {
                int next = i == 0 ? prefix[end + 1] : prefix[end + 1] - prefix[i - 1];
                if (next <= k) {
                    end++;
                } else {
                    break;
                }
            }

            string temp;
            for (int j = i; j <= end; j++) {
                temp += to_string(nums[j]);
                s.insert(temp);
                if (j != end) temp += ',';
            }
        }
        return s.size();
    }
};