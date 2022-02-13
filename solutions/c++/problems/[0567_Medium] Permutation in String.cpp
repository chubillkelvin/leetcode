class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();
        vector<int> count(26, 0);
        for (char c: s1) count[c - 'a']++;
        for (int i = 0; i < n; i++) {
            char c = s2[i];
            count[c - 'a']--;
            if (i >= k - 1) {
                bool matched = true;
                for (int num: count) {
                    if (num != 0) {
                        matched = false;
                        break;
                    }
                }
                if (matched) return true;
                count[s2[i - k + 1] - 'a']++;
            }
        }
        return false;
    }
};