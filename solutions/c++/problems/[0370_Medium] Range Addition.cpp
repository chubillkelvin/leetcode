class Solution {
public:
    vector<int> getModifiedArray(int length, vector <vector<int>> &updates) {
        int n = updates.size();
        vector<int> total(length, 0);
        for (int i = 0; i < n; i++) {
            total[updates[i][0]] += updates[i][2];
            if (updates[i][1] + 1 < length) total[updates[i][1] + 1] -= updates[i][2];
        }
        vector<int> ans(length, 0);
        int change = 0;
        for (int i = 0; i < length; i++) {
            change += total[i];
            ans[i] = change;
        }
        return ans;
    }
};