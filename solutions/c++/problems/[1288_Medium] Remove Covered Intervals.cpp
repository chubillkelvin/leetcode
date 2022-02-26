class Solution {
public:
    int removeCoveredIntervals(vector <vector<int>> &intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto &i1, auto &i2) {
            if (i1[0] < i2[0]) return true;
            if (i1[0] > i2[0]) return false;
            return i1[1] > i2[1];
        });
        int start = INT_MAX;
        int end = INT_MIN;
        int count = 0;
        for (auto interval: intervals) {
            int s = interval[0];
            int e = interval[1];
            if (s >= start && e <= end) {
                count++;
            } else {
                start = min(start, s);
                end = max(end, e);
            }
        }
        return n - count;
    }
};