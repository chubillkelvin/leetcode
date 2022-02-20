#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countEven(int num) {
        int count = 0;
        for (int i = 1; i <= num; i++) {
            string curr = to_string(i);
            int sum = 0;
            for (char c: curr) sum += c - '0';
            if (sum % 2 == 0) count++;
        }
        return count;
    }
};