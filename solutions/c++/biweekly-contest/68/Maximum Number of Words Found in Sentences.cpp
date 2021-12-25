#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int mostWordsFound(vector<string> &sentences) {
        int maxSpace = 1;
        for (string sentence: sentences) {
            int count = 1;
            for (char c: sentence) {
                if (c == ' ') count++;
            }
            maxSpace = max(maxSpace, count);
        }
        return maxSpace;
    }
};