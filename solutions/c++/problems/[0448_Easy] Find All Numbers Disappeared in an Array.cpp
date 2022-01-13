class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> appear(n, 0);
        for (int num: nums) appear[num - 1]++;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (appear[i] == 0) ans.push_back(i + 1);
        }
        return ans;
    }
};