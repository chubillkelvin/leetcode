class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s == t) return true;
        int n = s.size();
        int i = 0;
        for (char c: t) {
            if (s[i] == c) i++;
            if (i == n) return true;
        }
        return false;
    }
};