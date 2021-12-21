#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        int oneCount = 0;
        while (n > 0) {
            if (n & 1 == 1) oneCount++;
            n >>= 1;
        }
        return oneCount == 1;
    }
};