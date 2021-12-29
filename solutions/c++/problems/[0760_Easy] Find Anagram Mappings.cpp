class Solution {
public:
    vector<int> anagramMappings(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();
        unordered_map<int, vector<int>> mp1;
        unordered_map<int, vector<int>> mp2;
        for (int i = 0; i < n; i++) {
            mp1[nums1[i]].push_back(i);
            mp2[nums2[i]].push_back(i);
        }

        vector<int> ans = vector<int>(n);
        for (auto p: mp1) {
            for (int i = p.second.size() - 1; i >= 0; i--) {
                ans[p.second[i]] = mp2[p.first].back();
            }
        }
        return ans;
    }
};