class Solution {
public:
    bool isStrobogrammatic(string num) {
        int n = num.size();
        for (int i = 0; i <= n / 2; i++) {
            if (i == n - 1 - i) {
                if (num[i] == '0' || num[i] == '1' || num[i] == '8') continue;
                return false;
            } else {
                if (num[i] == '0' && num[n - 1 - i] == '0') continue;
                if (num[i] == '1' && num[n - 1 - i] == '1') continue;
                if (num[i] == '8' && num[n - 1 - i] == '8') continue;
                if (num[i] == '6' && num[n - 1 - i] == '9') continue;
                if (num[i] == '9' && num[n - 1 - i] == '6') continue;
                return false;
            }
        }
        return true;
    }
};