class Solution {
public:
    string getSmallestString(int n, int k) {
        vector<int> nums(n, 0);
        for (int i = 0; i < n; i++) {
            nums[i]++;
            k--;
        }
        int i = 0;
        while (k > 0) {
            nums[i] += min(k, 25);
            k -= min(k, 25);
            i++;
        }
        string ans = "";
        for (int i = n - 1; i >= 0; i--) ans += 'a' + nums[i] - 1;
        return ans;
    }
};