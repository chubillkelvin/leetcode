#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isSameAfterReversals(int num) {
        string test = to_string(num);
        bool hasNonZero = false;
        bool hasZeroEnd = false;
        for (int i = 0; i < test.size(); i++) {
            char c = test[i];
            if (hasNonZero && c == '0') {
                hasZeroEnd = true;
            } else if (c != '0') {
                hasZeroEnd = false;
                hasNonZero = true;
            }
        }
        return !(hasNonZero && hasZeroEnd);
    }
};