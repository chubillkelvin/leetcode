class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> pos(26);
        for (int i = 0; i < n; i++) {
            char c = s[i];
            pos[c - 'a'] = i;
        }
        vector<int> ans;
        int start = 0;
        while (start < n) {
            char c = s[start];
            int end = pos[c - 'a'];
            for (int i = start + 1; i < end; i++) {
                char c = s[i];
                end = max(end, pos[c - 'a']);
            }
            ans.push_back(end - start + 1);
            start = end + 1;
        }
        return ans;
    }
};
