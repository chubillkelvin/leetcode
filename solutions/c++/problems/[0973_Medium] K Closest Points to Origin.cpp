#include <bits/stdc++.h>

using namespace std;

class Point {
private:
    int x;
    int y;
    double dist;
public:
    Point(int _x, int _y) {
        x = _x;
        y = _y;
        dist = sqrt(pow(x, 2) + pow(y, 2));
    }

    vector<int> getPoint() {
        return {x, y};
    }

    double getDist() {
        return dist;
    }
};

bool comparePts(Point pt1, Point pt2) {
    return pt1.getDist() < pt2.getDist();
}

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k) {
        vector<Point> pts = {};
        for (vector<int> point: points) {
            Point *pt = new Point(point[0], point[1]);
            pts.push_back(pt);
        }

        sort(pts.begin(), pts.end(), comparePts);

        vector<vector<int>> ans = {};
        for (int i = 0; i < k; i++) {
            ans.push_back(pts[i].getPoint());
        }
        return ans;
    }
};