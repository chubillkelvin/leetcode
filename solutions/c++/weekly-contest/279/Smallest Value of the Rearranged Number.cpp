#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long smallestNumber(long long num) {
        string number = to_string(num);
        bool isNegative = number[0] == '-';
        if (isNegative) {
            sort(number.begin() + 1, number.end(), greater<char>());
            return stoll(number);
        } else {
            sort(number.begin(), number.end());
            char firstNonZero;
            for (char c: number) {
                if (c != '0') {
                    firstNonZero = c;
                    break;
                }
            }
            string ans = "";
            ans += firstNonZero;
            bool skipped = false;
            for (char c: number) {
                if (!skipped && c == firstNonZero) {
                    skipped = true;
                    continue;
                } else {
                    ans += c;
                }
            }
            return stoll(ans);
        }
        return 0;
    }
};