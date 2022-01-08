class Solution {
public:
    bool search(vector<int> &nums, int target) {
        set<int> numbers;
        for (int num: nums) numbers.insert(num);
        return numbers.count(target) > 0;
    }
};