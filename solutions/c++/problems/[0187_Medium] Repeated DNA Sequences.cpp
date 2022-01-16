class Solution {
public:
    vector <string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        if (n < 10) return {};
        unordered_map<string, int> memo;
        vector <string> ans;
        for (int i = 0; i <= n - 10; i++) {
            string seq = s.substr(i, 10);
            memo[seq]++;
            if (memo[seq] == 2) ans.push_back(seq);
        }
        return ans;
    }
};