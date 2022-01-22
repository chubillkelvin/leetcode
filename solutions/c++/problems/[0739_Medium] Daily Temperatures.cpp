class Solution {
public:
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        int n = temperatures.size();
        stack <pair<int, int>> temp;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            int curr = temperatures[i];
            if (temp.empty()) {
                temp.push(make_pair(curr, i));
            } else {
                while (!temp.empty() && curr > temp.top().first) {
                    ans[temp.top().second] = i - temp.top().second;
                    temp.pop();
                }
                temp.push(make_pair(curr, i));
            }
        }
        return ans;
    }
};