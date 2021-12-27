#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int number = num;
        int count = 0;
        while (number > 0) {
            count++;
            number >>= 1;
        }
        long bitMask = ((long) 1 << count) - 1;
        return num ^ bitMask;
    }
};