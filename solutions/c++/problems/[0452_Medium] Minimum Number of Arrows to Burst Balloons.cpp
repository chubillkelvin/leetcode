class Solution {
public:
    int findMinArrowShots(vector <vector<int>> &points) {
        sort(points.begin(), points.end(), [](vector<int> &p1, vector<int> &p2) {
            return p2[1] > p1[1];
        });
        int count = 1;
        int lastPos = points[0][1];
        for (auto pt: points) {
            if (pt[0] <= lastPos) continue;
            count++;
            lastPos = pt[1];
        }
        return count;
    }
};