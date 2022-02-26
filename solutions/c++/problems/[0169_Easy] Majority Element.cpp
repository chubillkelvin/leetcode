class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int maj = nums[0];
        int majCount = 1;
        unordered_map<int, int> count;
        for (int num: nums) {
            if (++count[num] > majCount) {
                majCount = count[num];
                maj = num;
            }
        }
        return maj;
    }
};