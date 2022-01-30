class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> h;
        h.push(-1);
        int area = 0;
        for (int i = 0; i < n; i++) {
            int curr = heights[i];
            while (h.top() != -1 && curr < heights[h.top()]) {
                int currHeight = heights[h.top()];
                h.pop();
                int currWidth = i - h.top() - 1;
                area = max(area, currHeight * currWidth);
            }
            h.push(i);
        }
        while (h.top() != -1) {
            int currHeight = heights[h.top()];
            h.pop();
            int currWidth = heights.size() - h.top() - 1;
            area = max(area, currHeight * currWidth);
        }
        return area;
    }
};