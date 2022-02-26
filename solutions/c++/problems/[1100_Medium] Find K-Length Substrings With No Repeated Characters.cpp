class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size();
        if (n < k) return 0;
        int count = 0;
        unordered_map<char, int> charCount;
        unordered_set<char> charSet;
        for (int i = 0; i < n; i++) {
            charCount[s[i]]++;
            charSet.insert(s[i]);
            if (i >= k - 1) {
                if (charSet.size() == k) count++;
                charCount[s[i - k + 1]]--;
                if (charCount[s[i - k + 1]] == 0) charSet.erase(s[i - k + 1]);
            }
        }
        return count;
    }
};