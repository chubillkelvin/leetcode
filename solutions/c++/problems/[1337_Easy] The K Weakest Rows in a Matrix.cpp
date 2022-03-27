class Solution {
public:
    vector<int> kWeakestRows(vector <vector<int>> &mat, int k) {
        int n = mat.size();
        vector <pair<int, int>> nums(n);
        for (int i = 0; i < n; i++) {
            auto row = mat[i];
            int total = 0;
            for (int num: row) total += num;
            nums[i] = (make_pair(total, i));
        }
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for (int i = 0; i < k; i++) ans.push_back(nums[i].second);
        return ans;
    }
};
