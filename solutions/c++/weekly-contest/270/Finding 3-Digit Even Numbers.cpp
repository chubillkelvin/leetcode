#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findEvenNumbers(vector<int> &digits) {
        set<int> ans = {};
        for (int i = 0; i < digits.size(); i++) {
            for (int j = i + 1; j < digits.size(); j++) {
                for (int k = j + 1; k < digits.size(); k++) {
                    int f = digits[i];
                    int s = digits[j];
                    int t = digits[k];
                    // fst
                    if (f != 0 && t % 2 == 0) {
                        int num = f * 100 + s * 10 + t;
                        ans.insert(num);
                    }
                    // fts
                    if (f != 0 && s % 2 == 0) {
                        int num = f * 100 + t * 10 + s;
                        ans.insert(num);
                    }
                    // sft
                    if (s != 0 && t % 2 == 0) {
                        int num = s * 100 + f * 10 + t;
                        ans.insert(num);
                    }
                    // stf
                    if (s != 0 && f % 2 == 0) {
                        int num = s * 100 + t * 10 + f;
                        ans.insert(num);
                    }
                    // tfs
                    if (t != 0 && s % 2 == 0) {
                        int num = t * 100 + f * 10 + s;
                        ans.insert(num);
                    }
                    // tsf
                    if (t != 0 && f % 2 == 0) {
                        int num = t * 100 + s * 10 + f;
                        ans.insert(num);
                    }
                }
            }
        }
        return vector<int>(ans.begin(), ans.end());
    }
};