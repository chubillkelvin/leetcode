#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        if (haystack == needle) return 0;
        if (m == 0) return 0;
        for (int i = 0; i < n - m + 1; i++) {
            char c1 = haystack[i];
            if (c1 == needle[0]) {
                bool isMatch = true;
                for (int j = 1; j < m; j++) {
                    char c2 = haystack[i + j];
                    char c3 = needle[j];
                    if (c2 != c3) isMatch = false;
                }
                if (isMatch) return i;
            }
        }
        return -1;
    }
};