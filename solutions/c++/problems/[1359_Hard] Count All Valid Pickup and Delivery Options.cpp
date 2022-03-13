class Solution {
public:
    int countOrders(int n) {
        int MOD = 1000000007;
        long long ans = 1;
        for (int i = 1; i <= 2 * n; i++) {
            ans *= i;
            if (i % 2 == 0) ans /= 2;
            ans %= MOD;
        }
        return ans;
    }
};