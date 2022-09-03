#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convert(int num, int base) {
        stack<int> st;
        while (num > 0) {
            st.push(num % base);
            num /= base;
        }
        string s;
        while (!st.empty()) {
            s += st.top();
            st.pop();
        }
        return s;
    }

    bool isPalindrome(string s) {
        int n = s.size();
        for (int i = 0; i < n / 2; i++) {
            if (s[i] != s[n - 1 - i]) return false;
        }
        return true;
    }

    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            auto s = convert(n, i);
            if (!isPalindrome(s)) return false;
        }
        return true;
    }
};