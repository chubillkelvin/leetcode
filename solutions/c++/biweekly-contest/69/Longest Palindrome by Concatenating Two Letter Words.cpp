#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string word) {
        string s = word;
        reverse(s.begin(), s.end());
        return word == s;
    }

    int longestPalindrome(vector<string> &words) {
        int n = words.size();
        unordered_map<string, int> single;
        vector<string> palindromes;
        int pairCount = 0;
        for (int i = 0; i < n; i++) {
            string word = words[i];
            if (isPalindrome(word)) {
                if (single[word] > 0) {
                    pairCount += word.size() * 2;
                    single[word]--;
                } else {
                    palindromes.push_back(word);
                    single[word]++;
                }
            } else {
                string reversed = word;
                reverse(reversed.begin(), reversed.end());
                if (single[reversed] > 0) {
                    pairCount += word.size() * 2;
                    single[reversed]--;
                } else {
                    single[word]++;
                }
            }
        }
        int longestP = 0;
        for (auto w: palindromes) {
            if (single[w] > 0) longestP = max(longestP, (int) w.size());
        }
        return longestP + pairCount;
    }
};