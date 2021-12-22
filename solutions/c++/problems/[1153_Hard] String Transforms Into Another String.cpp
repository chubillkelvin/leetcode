#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        int n = str1.size();
        map<char, char> charMap;
        set<char> charSet1;
        set<char> charSet2;
        for (int i = 0; i < n; i++) {
            char c1 = str1[i];
            charSet1.insert(c1);
            char c2 = str2[i];
            charSet2.insert(c2);
            if (!charMap[c1]) {
                charMap[c1] = c2;
            } else if (charMap[c1] != c2) {
                return false;
            }
        }
        return charMap.size() < 26 || charSet2.size() < charSet1.size();
    }
};