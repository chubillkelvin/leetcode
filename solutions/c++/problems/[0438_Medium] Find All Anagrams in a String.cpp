class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<int> checkSet(26, 0);
        vector<int> ans;
        for (char c: p) checkSet[c - 'a']++;
        for (int i = 0; i < n - m + 1; i++) {
            if (i == 0) {
                for (char c: s.substr(0, m)) checkSet[c - 'a']--;
            } else {
                checkSet[s[i - 1] - 'a']++;
                checkSet[s[i + m - 1] - 'a']--;
            }
            bool isAnagram = true;
            for (int num: checkSet) {
                if (num != 0) {
                    isAnagram = false;
                    break;
                }
            }
            if (isAnagram) ans.push_back(i);
        }
        return ans;
    }
};