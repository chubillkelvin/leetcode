class Solution {
public:
    int countQuadruplets(vector<int> &nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 3; i < n; i++) {
            int target = nums[i];
            for (int x = 0; x < i; x++) {
                for (int y = x + 1; y < i; y++) {
                    for (int z = y + 1; z < i; z++) {
                        int sum = nums[x] + nums[y] + nums[z];
                        if (sum == target) count++;
                    }
                }
            }
        }
        return count;
    }
};