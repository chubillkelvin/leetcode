class Solution {
public:
    int countGoodRectangles(vector <vector<int>> &rectangles) {
        int n = rectangles.size();
        int maxSize = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int curr = min(rectangles[i][0], rectangles[i][1]);
            if (curr > maxSize) {
                maxSize = curr;
                count = 1;
            } else if (curr == maxSize) {
                count++;
            }
        }
        return count;
    }
};