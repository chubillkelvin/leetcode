class Solution {
public:
    int maxProduct(vector <string> &words) {
        int n = words.size();
        unordered_map<string, int> mp;
        for (auto word: words) {
            int mask = 0;
            for (char c: word) {
                mask |= 1 << c - 'a';
            }
            mp[word] = mask;
        }
        int maxSoFar = 0;
        for (int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            for (int j = i + 1; j < n; j++) {
                string s2 = words[j];
                if ((mp[s1] & mp[s2]) == 0) {
                    int product = s1.size() * s2.size();
                    maxSoFar = max(maxSoFar, product);
                }
            }
        }
        return maxSoFar;
    }
};