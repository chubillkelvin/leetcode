class Solution {
public:
    int findPairs(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> numbers;
        int count = 0;
        for (int num: nums) {
            if (numbers[num] == 0) {
                if (numbers[num - k]) count++;
                numbers[num]++;
            } else if (numbers[num] == 1 && k == 0) {
                count++;
                numbers[num]++;
            }
        }
        return count;
    }
};