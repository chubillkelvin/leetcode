#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int maxDiff(int num) {
        if (num < 10) return 8;
        string s = "";
        for (char c: to_string(num)) s += c;
        char firstChar = s[0];
        char secondChar1 = s[1];
        char secondChar2 = s[1];
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != firstChar) {
                secondChar1 = s[i];
                break;
            }
        }
        for (int i = 1; i < s.size(); i++) {
            if (s[i] != firstChar && s[i] != '0') {
                secondChar2 = s[i];
                break;
            }
        }
        string s1, s2;
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            char c1 = curr, c2 = curr;
            if (curr == firstChar) {
                c1 = '9';
                c2 = '1';
            }
            if (firstChar == '9' && secondChar1 != firstChar && curr == secondChar1) {
                c1 = '9';
            }
            if (firstChar == '1' && secondChar2 != firstChar && curr == secondChar2) {
                c2 = '0';
            }
            s1 += c1;
            s2 += c2;
        }
        int num1 = stoi(s1);
        int num2 = stoi(s2);
        return num1 - num2;
    }
};