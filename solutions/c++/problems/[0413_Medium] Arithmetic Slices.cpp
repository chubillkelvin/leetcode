class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        int n = nums.size();
        if (n < 3) return 0;
        vector<int> temp;
        int count = 0;
        for (int i = 0; i < n; i++) {
            temp.push_back(nums[i]);
            int m = temp.size();
            if (m >= 3) {
                if (temp[1] - temp[0] == temp[m - 1] - temp[m - 2]) {
                    count += m - 2;
                } else {
                    temp = {temp[m - 2], temp[m - 1]};
                }
            }
        }
        return count;
    }
};