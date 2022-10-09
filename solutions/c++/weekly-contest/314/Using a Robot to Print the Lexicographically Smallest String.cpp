#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        char smallestC = 'z';
        int smallestIndex = n - 1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c < smallestC) {
                smallestC = c;
                smallestIndex = i;
            } else if (c == smallestC) {
                smallestIndex = min(smallestIndex, i);
            }
        }
        string ans;
        ans += smallestC;
        stack<char> st;
        for (int i = 0; i < smallestIndex; i++) st.push(s[i]);
        multiset<char> chars;
        for (int i = smallestIndex + 1; i < n; i++) chars.insert(s[i]);
        for (int i = smallestIndex + 1; i < n; i++) {
            char c = s[i];
            if (st.empty()) {
                st.push(c);
                chars.erase(chars.find(c));
                continue;
            }
            auto lb = chars.lower_bound(st.top());
            while (lb == chars.begin() && st.top() <= *lb) {
                ans += st.top();
                st.pop();
                if (st.empty()) break;
                lb = chars.lower_bound(st.top());
            }
            st.push(c);
            chars.erase(chars.find(c));
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};