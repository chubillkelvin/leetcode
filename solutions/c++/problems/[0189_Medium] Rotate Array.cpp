class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> rotated(n, 0);
        for (int i = 0; i < n; i++) {
            int newIndex = (i - k) % n;
            if (newIndex < 0) newIndex += n;
            rotated[i] = nums[newIndex];
        }
        for (int i = 0; i < n; i++) {
            nums[i] = rotated[i];
        }
    }
};