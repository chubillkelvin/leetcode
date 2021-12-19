#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string> &words) {
        for (auto word: words) {
            int n = word.size();
            bool isPalindrome = true;
            for (int i = 0; i < n / 2; i++) {
                char c1 = word[i];
                char c2 = word[n - 1 - i];
                if (c1 != c2) {
                    isPalindrome = false;
                    break;
                };
            }
            if (isPalindrome) return word;
        }
        return "";
    }
};