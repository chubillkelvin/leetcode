class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            char c = word[i];
            if (c - 'A' <= 26) {
                if (i == 0) continue;
                if (word[i - 1] - 'A' <= 26) continue;
                return false;
            } else {
                if (i <= 1) continue;
                if (word[i - 1] - 'A' <= 26) return false;
            }
        }
        return true;
    }
};