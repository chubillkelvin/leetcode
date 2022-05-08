#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();
        stack<int> st;
        int maxNum = -1;
        for (int i = 0; i < n; i++) {
            if (st.empty() || num[i] != num[i - 1]) {
                st.push(1);
            } else {
                st.top()++;
                if (st.top() >= 3) {
                    int curr = num[i] - '0';
                    maxNum = max(maxNum, curr);
                }
            }
        }
        if (maxNum == -1) return "";
        string ans;
        ans += to_string(maxNum);
        ans += to_string(maxNum);
        ans += to_string(maxNum);
        return ans;
    }
};