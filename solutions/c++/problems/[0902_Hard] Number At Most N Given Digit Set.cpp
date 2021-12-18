#include <bits/stdc++.h>

using namespace std;

class Solution {
public:

    int atMostNGivenDigitSet(vector<string> &digits, int n) {
        if (n < stoi(digits[0])) return 0;

        vector<int> digitSet;
        for (auto digit: digits) digitSet.push_back(stoi(digit));
        int totalNumberOfDigits = digitSet.size();

        int digitsInN = log10(n) + 1;
        vector<int> targetDigits;
        for (int i = digitsInN - 1; i >= 0; i--) {
            int digit = n % ((long) pow(10, i + 1)) / pow(10, i);
            targetDigits.push_back(digit);
        }

        int ans = 0;
        for (int i = 1; i < digitsInN; i++) {
            ans += pow(totalNumberOfDigits, i);
        }

        for (int i = 0; i < digitsInN; i++) {
            bool hasSameDigit = false;
            int target = targetDigits[i];
            for (int digit: digitSet) {
                if (digit < target) {
                    ans += pow(totalNumberOfDigits, digitsInN - 1 - i);
                } else if (digit == target) {
                    hasSameDigit = true;
                }
            }
            if (!hasSameDigit) return ans;
        }
        // has exact same number, add 1 extra count
        return ans + 1;
    }
};