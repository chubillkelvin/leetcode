#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n, m;
    vector<vector<int>> ans;
    vector<int> numbers;
    vector<int> mults;

    int solve(int currIndex, int left) {
        if (currIndex >= n || currIndex >= m) return 0;
        if (ans[currIndex][left] != 0) return ans[currIndex][left];

        int multiplier = mults[currIndex];
        int front = numbers[left];
        int back = numbers[n - 1 - (currIndex - left)];
        int res = max(front * multiplier + solve(currIndex + 1, left + 1),
                      back * multiplier + solve(currIndex + 1, left));
        ans[currIndex][left] = res;
        return res;
    }

    int maximumScore(vector<int> &nums, vector<int> &multipliers) {
        n = nums.size();
        m = multipliers.size();
        ans = vector<vector<int>>(m, vector<int>(m, 0));
        numbers = nums;
        mults = multipliers;
        return solve(0, 0);
    }
};