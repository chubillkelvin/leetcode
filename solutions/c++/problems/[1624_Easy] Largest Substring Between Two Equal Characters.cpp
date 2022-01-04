class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int n = s.size();
        vector<int> pos(26, -1);
        int longest = -1;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            int idx = c - 'a';
            if (pos[idx] == -1) {
                pos[idx] = i;
            } else {
                longest = max(longest, i - pos[idx] - 1);
            }
        }
        return longest;
    }
};