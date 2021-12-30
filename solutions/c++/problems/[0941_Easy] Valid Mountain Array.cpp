class Solution {
public:
    bool validMountainArray(vector<int> &arr) {
        int n = arr.size();
        if (n < 3) return false;
        bool isIncreasing = true;
        for (int i = 1; i < n; i++) {
            int prev = arr[i - 1];
            int curr = arr[i];
            if (isIncreasing) {
                if (curr == prev) return false;
                if (curr < prev) isIncreasing = false;
            } else {
                if (curr >= prev) return false;
            }
        }
        return arr[0] < arr[1] && !isIncreasing;
    }
};