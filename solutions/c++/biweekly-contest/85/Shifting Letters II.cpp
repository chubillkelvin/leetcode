#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char shiftChar(char c, int shift) {
        int curr = c - 'a';
        curr += shift;
        if (curr < 0) {
            curr += 26 * ((curr * -1) / 26 + 1);
        }
        curr %= 26;
        return 'a' + curr;
    }

    string shiftingLetters(string s, vector<vector<int>> &shifts) {
        int n = s.size();
        vector<int> count(n, 0);
        for (auto sh: shifts) {
            int start = sh[0];
            int end = sh[1];
            if (sh[2] == 1) {
                count[start]++;
                if (end + 1 < n) count[end + 1]--;
            } else {
                count[start]--;
                if (end + 1 < n) count[end + 1]++;
            }
        }
        int curr = 0;
        string ans;
        for (int i = 0; i < n; i++) {
            curr += count[i];
            ans += shiftChar(s[i], curr);
        }
        return ans;
    }
};