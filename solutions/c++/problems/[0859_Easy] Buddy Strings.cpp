class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if (n != m || n == 1) return false;
        unordered_map<char, bool> counts;
        bool hasSameLetter = false;
        int diff = 0;
        vector<char> diffChars;
        for (int i = 0; i < n; i++) {
            char c1 = s[i];
            char c2 = goal[i];
            if (c1 != c2) {
                if (diff == 0) {
                    diffChars.push_back(c1);
                    diffChars.push_back(c2);
                } else {
                    if (diffChars[0] != c2 || diffChars[1] != c1) return false;
                }
                diff++;
            } else {
                if (!hasSameLetter) {
                    if (counts[c1]) {
                        hasSameLetter = true;
                    } else {
                        counts[c1] = true;
                    }
                }
            }
        }
        if (diff != 0 && diff != 2) return false;
        if (diff == 0) return hasSameLetter;
        return diffChars.size() == 2;
    }
};