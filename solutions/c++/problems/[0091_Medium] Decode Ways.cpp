class Solution {
    vector<int> memo;
    string s;
    int n;
public:
    int dp(int i) {
        if (i >= n) return 1;
        if (memo[i]) return memo[i];
        if (s[i] == '0') return 0;
        if (i == n - 1) return 1;
        string s2 = s.substr(i, 2);
        if (s2 == "10" || s2 == "20") {
            memo[i] = dp(i + 2);
        } else if (stoi(s2) <= 26) {
            memo[i] = dp(i + 1) + dp(i + 2);
        } else {
            memo[i] = dp(i + 1);
        }
        return memo[i];
    }

    int numDecodings(string s) {
        this->s = s;
        n = s.size();
        memo = vector<int>(n, 0);
        return dp(0);
    }
};