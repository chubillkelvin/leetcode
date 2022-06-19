#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    char endWith(int num) {
        return to_string(num).back();
    }

    int minimumNumbers(int num, int k) {
        if (num == 0) return 0;
        if (num == k) return 1;
        if (k == 0) {
            if (num % 10 == 0) return 1;
            return -1;
        }
        char end = to_string(k).back();
        if (to_string(num).back() == end) return 1;
        int count = 0;
        while (num >= k) {
            count++;
            num -= k;
            if (endWith(num) == end) break;
        }
        if (endWith(num) == end) return count + 1;
        return -1;
    }
};