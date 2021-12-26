#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        bool isNegative = num < 0;
        if (isNegative) num *= -1;
        stack<int> r;
        while (num > 0) {
            r.push(num % 7);
            num /= 7;
        }
        string ans = "";
        while (!r.empty()) {
            if (r.top() == 0 && ans.size() == 0) {
                r.pop();
                continue;
            }
            ans += to_string(r.top());
            r.pop();
        }
        return isNegative ? "-" + ans : ans;
    }
};