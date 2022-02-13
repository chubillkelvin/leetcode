class Solution {
public:
    vector <vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        vector <vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < n; i++) {
            auto curr = ans;
            for (auto item: curr) {
                item.push_back(nums[i]);
                ans.push_back(item);
            }
        }
        return ans;
    }
};