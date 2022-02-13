class Solution {
public:
    vector <vector<int>> getSkyline(vector <vector<int>> &buildings) {
        vector <pair<int, int>> start;
        vector <pair<int, int>> end;
        for (auto b: buildings) {
            start.push_back(make_pair(b[0], b[2]));
            end.push_back(make_pair(b[1], b[2]));
        }
        sort(start.begin(), start.end(), [](auto &s1, auto &s2) {
            if (s1.first < s2.first) return true;
            if (s1.first > s2.first) return false;
            return s1.second > s2.second;
        });
        sort(end.begin(), end.end());
        vector <vector<int>> ans;
        priority_queue<int> height;
        priority_queue<int> popped;
        height.push(0);
        int j = 0;
        for (int i = 0; i < start.size(); i++) {
            auto curr = start[i];
            int prevHeight = height.top();
            height.push(curr.second);
            if (height.top() != prevHeight) {
                ans.push_back({curr.first, height.top()});
            }
            while (j < end.size() && (i == start.size() - 1 || start[i + 1].first > end[j].first)) {
                auto currEnd = end[j];
                prevHeight = height.top();
                popped.push(currEnd.second);
                while (!popped.empty() && height.top() == popped.top()) {
                    height.pop();
                    popped.pop();
                }
                if (height.top() != prevHeight) {
                    ans.push_back({currEnd.first, height.top()});
                }
                j++;
            }
        }
        return ans;
    }
};