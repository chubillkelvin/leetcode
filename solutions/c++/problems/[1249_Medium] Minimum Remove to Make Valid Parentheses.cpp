class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<int> brackets;
        vector<int> invalid;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            if (c == '(') {
                brackets.push_back(i);
            } else if (c == ')') {
                if (brackets.empty()) {
                    invalid.push_back(i);
                } else {
                    brackets.pop_back();
                }
            }
        }
        invalid.insert(invalid.end(), brackets.begin(), brackets.end());
        sort(invalid.begin(), invalid.end());
        int m = invalid.size();
        int j = 0;
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (j < m && i == invalid[j]) {
                j++;
            } else {
                ans += s[i];
            }
        }
        return ans;
    }
};