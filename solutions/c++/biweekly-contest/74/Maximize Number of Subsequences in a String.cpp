#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    long long fact(long long n) {
        return (n + 1) * n / 2;
    }

    long long maximumSubsequenceCount(string text, string pattern) {
        int n = text.size();
        char c1 = pattern[0];
        char c2 = pattern[1];
        queue<int> c1Idx;
        queue<int> c2Idx;
        for (int i = 0; i < n; i++) {
            char c = text[i];
            if (c == c1) {
                c1Idx.push(i);
            } else if (c == c2) {
                c2Idx.push(i);
            }
        }
        if (c1 != c2) {
            long long count = max(c1Idx.size(), c2Idx.size());
            while (!c1Idx.empty()) {
                int curr = c1Idx.front();
                c1Idx.pop();
                while (!c2Idx.empty() && c2Idx.front() < curr) c2Idx.pop();
                count += c2Idx.size();
            }
            return count;
        } else {
            return fact(c1Idx.size());
        }
    }
};