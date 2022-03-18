class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        vector <vector<int>> q(26);
        for (int i = 0; i < n; i++) q[s[i] - 'a'].push_back(i);
        string ans = "";
        unordered_set<char> charSet;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (charSet.count(c) == 0) {
                while (!ans.empty() && ans.back() > c && q[ans.back() - 'a'].back() > i) {
                    charSet.erase(ans.back());
                    ans.pop_back();
                }
                charSet.insert(c);
                ans += c;
            }
        }
        return ans;
    }
};