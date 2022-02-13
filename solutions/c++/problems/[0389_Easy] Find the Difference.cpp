class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> chars(26, 0);
        for (char c: s) chars[c - 'a']++;
        for (char c: t) if (--chars[c - 'a'] < 0) return c;
        return t[0];
    }
};