class Solution {
public:
    bool carPooling(vector <vector<int>> &trips, int capacity) {
        vector<int> passengers(1001, 0);
        for (auto trip: trips) {
            for (int i = trip[1]; i < trip[2]; i++) {
                passengers[i] += trip[0];
                if (passengers[i] > capacity) return false;
            }
        }
        return true;
    }
};