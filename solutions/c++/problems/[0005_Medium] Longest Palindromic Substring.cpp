class Solution {
public:
    string longestPalindrome(string s) {
        string padded = "#";
        for (char c: s) padded = padded + c + "#";
        int n = padded.size();
        string longest = "";
        for (int i = 0; i < n; i++) {
            int len = 0;
            for (int j = 1; i - j >= 0 && i + j < n; j++) {
                if (padded[i - j] != padded[i + j]) break;
                len = j;
            }
            string curr = padded.substr(i - len, 2 * len + 1);
            if (curr.size() > longest.size()) longest = curr;
        }
        string ans = "";
        for (char c: longest) if (c != '#') ans += c;
        return ans;
    }
};