class Solution {
public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
        vector<int> nums(2001, 0);
        for (int num: arr1) nums[num]++;
        for (int num: arr2) nums[num]++;
        for (int num: arr3) nums[num]++;
        vector<int> ans;
        for (int i = 0; i < 2001; i++) {
            if (nums[i] == 3) ans.push_back(i);
        }
        return ans;
    }
};