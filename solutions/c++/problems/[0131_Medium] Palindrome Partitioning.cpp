class Solution {
    string s;
    int n;
public:
    void getPalindrome(int start, vector <string> p, vector <vector<string>> &ans) {
        if (start >= n) return ans.push_back(p);
        for (int i = 0; i < n - start; i++) {
            string s1 = s.substr(start, i + 1);
            string s2 = string(s1.rbegin(), s1.rend());
            if (s1 == s2) {
                p.push_back(s1);
                getPalindrome(start + i + 1, p, ans);
                p.pop_back();
            }
        }
    }

    vector <vector<string>> partition(string s) {
        this->s = s;
        this->n = s.size();
        vector <vector<string>> ans;
        for (int i = 0; i < n; i++) {
            string s1 = s.substr(0, i + 1);
            string s2 = string(s1.rbegin(), s1.rend());
            if (s1 == s2) {
                getPalindrome(i + 1, vector < string > {s1}, ans);
            }
        }
        return ans;
    }
};