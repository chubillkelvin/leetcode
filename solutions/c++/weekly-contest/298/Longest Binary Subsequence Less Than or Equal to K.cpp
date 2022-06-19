#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        string temp;
        long long curr = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (k / 2 >= curr && temp.size() < 64) {
                string next = s[i] + temp;
                auto val = bitset<1000>(next).to_ullong();
                if (val <= k) {
                    temp = next;
                }
            } else if (s[i] == '0') {
                temp = s[i] + temp;
            }
        }
        return temp.size();
    }
};