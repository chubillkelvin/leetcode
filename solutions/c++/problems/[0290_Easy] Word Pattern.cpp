class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp1;
        unordered_map<string, char> mp2;
        vector <string> words;
        int n = s.size();
        string curr = "";
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == ' ') {
                words.push_back(curr);
                curr = "";
            } else {
                curr += c;
            }
        }
        words.push_back(curr);
        int m = pattern.size();
        if (words.size() != m) return false;
        for (int i = 0; i < m; i++) {
            char p = pattern[i];
            string word = words[i];
            if (mp1.find(p) == mp1.end() && mp2.find(word) == mp2.end()) {
                mp1[p] = word;
                mp2[word] = p;
            } else {
                if (mp1[p] != word) return false;
                if (mp2[word] != p) return false;
            }
        }
        return true;
    }
};