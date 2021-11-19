#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countSetBits(int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }

    int hammingDistance(int x, int y) {
        return countSetBits(x^y);
    }
};