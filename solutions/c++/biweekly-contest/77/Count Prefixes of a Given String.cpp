#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countPrefixes(vector<string> &words, string s) {
        int count = 0;
        for (auto word: words) {
            bool match = true;
            for (int i = 0; i < word.size(); i++) {
                char c = word[i];
                if (s[i] != c) {
                    match = false;
                    break;
                }
            }
            if (match) count++;
        }
        return count;
    }
};