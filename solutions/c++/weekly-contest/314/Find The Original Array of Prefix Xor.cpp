#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findArray(vector<int> &pref) {
        int n = pref.size();
        vector<int> ans(n);
        vector<int> currXor(n);
        ans[0] = pref[0];
        currXor[0] = ans[0];
        for (int i = 1; i < n; i++) {
            ans[i] = currXor[i - 1] ^ pref[i];
            currXor[i] = currXor[i - 1] ^ ans[i];
        }
        return ans;
    }
};