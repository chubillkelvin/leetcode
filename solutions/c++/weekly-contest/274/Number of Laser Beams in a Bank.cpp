#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string> &bank) {
        int n = bank.size();
        vector<int> counts(n, 0);
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (char c: bank[i]) {
                if (c == '1') count++;
            }
            counts[i] = count;
        }

        stack<int> countStack;
        int total = 0;
        for (int i = 0; i < n; i++) {
            int curr = counts[i];
            if (curr > 0) {
                if (!countStack.empty()) {
                    int prev = countStack.top();
                    total += prev * curr;
                    countStack.pop();
                }
                countStack.push(curr);
            }
        }
        return total;
    }
};