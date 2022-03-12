class Solution {
public:
    vector <string> summaryRanges(vector<int> &nums) {
        vector <string> ans;
        if (nums.empty()) return ans;
        string temp = to_string(nums[0]);
        long first = nums[0];
        long last = nums[0];
        for (int num: nums) {
            if (num - last <= 1) {
                last = num;
            } else {
                if (last != first) {
                    temp += "->";
                    temp += to_string(last);
                }
                ans.push_back(temp);
                first = num;
                last = num;
                temp = to_string(num);
            }
        }
        if (last != first) {
            temp += "->";
            temp += to_string(last);
        }
        ans.push_back(temp);
        return ans;
    }
};