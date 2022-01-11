class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> mp1(26, 0);
        vector<int> mp2(26, 0);
        for (char c: s) mp1[c - 'a']++;
        for (char c: t) mp2[c - 'a']++;
        int count = 0;
        for (int i = 0; i < 26; i++) {
            count += abs(mp1[i] - mp2[i]);
        }
        return count / 2;
    }
};