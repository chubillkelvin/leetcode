class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string s = "";
        for (int i = 0; i < n; i++) {
            char c = num[i];
            while (k > 0 && !s.empty() && c < s.back()) {
                s.pop_back();
                k--;
            }
            if (!s.empty() || c != '0') s += c;
        }
        while (k > 0 && !s.empty()) {
            s.pop_back();
            k--;
        }
        return s.empty() ? "0" : s;
    }
};