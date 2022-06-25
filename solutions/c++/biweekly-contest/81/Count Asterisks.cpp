#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        bool notCount = false;
        int temp = 0;
        int count = 0;
        for (char c: s) {
            if (c == '*') {
                if (notCount) {
                    temp++;
                } else {
                    count++;
                }
            } else if (c == '|') {
                if (notCount) {
                    temp = 0;
                    notCount = false;
                } else {
                    notCount = true;
                }
            }
        }
        return count + temp;
    }
};