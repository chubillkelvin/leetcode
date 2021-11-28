#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        stack<int> s = {};
        stack<int> index = {};
        s.push(nums[0]);
        index.push(0);
        vector<int> ans = vector<int>(nums.size(), -1);

        for (int i = 1; i < nums.size(); i++) {
            int num = nums[i];

            while (!s.empty() && num > s.top()) {
                int topIndex = index.top();
                ans[topIndex] = num;
                index.pop();
                s.pop();
            }

            index.push(i);
            s.push(num);
        }

        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];

            while (!s.empty() && num > s.top()) {
                int topIndex = index.top();
                ans[topIndex] = num;
                index.pop();
                s.pop();
            }

            index.push(i);
            s.push(num);
        }

        return ans;
    }
};
