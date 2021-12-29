class Solution {
public:
    int heightChecker(vector<int> &heights) {
        int n = heights.size();
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] != sorted[i]) count++;
        }
        return count;
    }
};