class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        unordered_map<char, vector<int>> pos;
        for (int i = 0; i < n; i++) {
            pos[s[i]].push_back(i);
        }
        unordered_map<string, int> mp;
        for (auto p: pos) {
            char c = p.first;
            auto arr = p.second;
            if (arr.size() <= 1) continue;
            for (int i = arr[0] + 1; i < arr.back(); i++) {
                string newS;
                newS += c;
                newS += s[i];
                newS += c;
                mp[newS]++;
            }
        }
        return mp.size();
    }
};