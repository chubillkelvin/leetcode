#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bulls = 0;
        vector<int> secretCount = vector<int>(10, 0);
        vector<int> guessCount = vector<int>(10, 0);
        for (int i = 0; i < n; i++) {
            int s = secret[i] - '0';
            int g = guess[i] - '0';
            if (s == g) {
                bulls++;
            } else {
                secretCount[s]++;
                guessCount[g]++;
            }
        }
        int cows = 0;
        for (int i = 0; i < 10; i++) {
            cows += min(secretCount[i], guessCount[i]);
        }
        string ans = to_string(bulls) + 'A' + to_string(cows) + 'B';
        return ans;
    }
};