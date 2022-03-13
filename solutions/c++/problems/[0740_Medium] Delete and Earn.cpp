class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        vector<int> val(20001, 0);
        for (int num: nums) val[num]++;
        for (int i = 0; i < 20001; i++) val[i] *= i;
        vector<int> memo(20001, 0);
        memo[0] = 0;
        memo[1] = val[1];
        for (int i = 2; i < 20001; i++) memo[i] = max(memo[i - 1], memo[i - 2] + val[i]);
        return memo[20000];
    }
};