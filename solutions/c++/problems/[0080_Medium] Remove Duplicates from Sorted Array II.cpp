class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int count = 0;
        for (int i = 2; i < nums.size(); i++) {
            int prev1 = nums[i - 2];
            int prev2 = nums[i - 1];
            int curr = nums[i];
            if (prev1 == prev2 && prev1 == curr) {
                count++;
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};