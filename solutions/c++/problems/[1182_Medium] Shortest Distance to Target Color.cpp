class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector <vector<int>> &queries) {
        int n = colors.size();
        vector<int> one;
        vector<int> two;
        vector<int> three;
        for (int i = 0; i < n; i++) {
            int color = colors[i];
            auto &indexes = color == 1 ? one : color == 2 ? two : three;
            int topIndex = indexes.empty() ? -n : indexes.size() - 1;
            for (int j = topIndex >= 0 ? topIndex + 1 : 0; j <= i; j++) {
                int diffTop = abs(j - topIndex);
                int diffCurr = abs(j - i);
                indexes.push_back(min(diffTop, diffCurr));
            }
        }
        int count = 1;
        while (!one.empty() && one.size() < n) one.push_back(count++);
        count = 1;
        while (!two.empty() && two.size() < n) two.push_back(count++);
        count = 1;
        while (!three.empty() && three.size() < n) three.push_back(count++);
        int m = queries.size();
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int pos = queries[i][0];
            int color = queries[i][1];
            auto &indexes = color == 1 ? one : color == 2 ? two : three;
            if (indexes.empty()) {
                ans[i] = -1;
            } else {
                ans[i] = indexes[pos];
            }
        }
        return ans;
    }
};