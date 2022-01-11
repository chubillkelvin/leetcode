class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int carry = 0;
        while (a.size() > 0 || b.size() > 0) {
            char c1 = a.empty() ? '0' : a.back();
            char c2 = b.empty() ? '0' : b.back();
            if (c1 == '1') carry++;
            if (c2 == '1') carry++;
            if (carry % 2 == 1) {
                ans += '1';
            } else {
                ans += '0';
            }
            carry /= 2;
            if (!a.empty()) a.pop_back();
            if (!b.empty()) b.pop_back();
        }
        if (carry == 1) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }
};