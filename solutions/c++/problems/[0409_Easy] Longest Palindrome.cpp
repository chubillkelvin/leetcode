class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> charSet(60, 0);
        for (char c: s) charSet[c - 'A']++;
        bool hasSingle = false;
        int count = 0;
        for (int i = 0; i < 60; i++) {
            int curr = charSet[i];
            if (curr >= 2) {
                count += curr % 2 == 0 ? curr : curr - 1;
                curr %= 2;
            }
            if (curr == 1 && !hasSingle) {
                hasSingle = true;
                count++;
            }
        }
        return count;
    }
};