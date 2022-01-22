class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        vector <pair<int, int>> s;
        int count = 0;
        if (height[0] > 0) s.push_back(make_pair(height[0], 0));
        for (int i = 1; i < n; i++) {
            int curr = height[i];
            while (!s.empty() && curr >= s[0].first) {
                auto temp = s.back();
                s.pop_back();
                if (!s.empty()) {
                    count += s[0].first - temp.first;
                }
            }
            s.push_back(make_pair(curr, i));
        }
        if (s.size() > 1) {
            vector<int> next;
            int m = s.size();
            next.push_back(0);
            int maxi = s[1].first;
            for (int i = 1; i < m; i++) {
                next.push_back(s[i].first);
                maxi = max(maxi, s[i].first);
            }
            next[0] = maxi;
            count += trap(next);
        }
        return count;
    }
};