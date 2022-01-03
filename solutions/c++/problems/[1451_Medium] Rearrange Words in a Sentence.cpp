class Solution {
public:
    string arrangeWords(string text) {
        int n = text.size();
        unordered_map<int, vector<string>> mp;
        text[0] += 32;
        for (int i = 0; i < n; i++) {
            string word = "";
            for (int j = i; j < n; j++) {
                char c = text[j];
                if (c != ' ') {
                    word += c;
                } else {
                    break;
                }
                i = j;
            }
            mp[word.size()].push_back(word);
        }
        string ans = "";
        for (int i = 1; i <= n; i++) {
            auto curr = mp[i];
            for (auto word: curr) {
                ans += word;
                ans += ' ';
            }
        }
        ans[0] -= 32;
        ans.pop_back();
        return ans;
    }
};