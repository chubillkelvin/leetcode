#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<vector<int>> result;
public:
    void helper(vector<int> nums, int curr, int k, vector<int> comb) {
        if (comb.size() == k) {
            result.push_back(comb);
            return;
        }
        for (int i = curr; i < nums.size(); i++) {
            comb.push_back(nums[i]);
            helper(nums, i + 1, k, comb);
            comb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for (int i = 0; i < n; i++) nums.push_back(i);
        helper(nums, 0, k, vector<int>());
        return result;
    }

    int maximumRows(vector<vector<int>> &mat, int cols) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> bs;
        for (int i = 0; i < m; i++) {
            vector<int> curr;
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) curr.push_back(j);
            }
            bs.push_back(curr);
        }
        int maxRows = 0;
        auto raw = combine(n, cols);
        vector<unordered_set<int>> com;
        for (auto r: raw) {
            unordered_set<int> s;
            for (auto num: r) s.insert(num);
            com.push_back(s);
        }
        for (auto c: com) {
            int count = 0;
            for (int i = 0; i < m; i++) {
                auto b = bs[i];
                bool shouldCount = true;
                for (int index: b) {
                    if (!c.count(index)) {
                        shouldCount = false;
                        break;
                    }
                }
                if (shouldCount) count++;
            }
            maxRows = max(maxRows, count);
        }
        return maxRows;
    }
};