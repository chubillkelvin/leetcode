class Solution {
public:
    int fixedPoint(vector<int> &arr) {
        int lo = 0;
        int hi = arr.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] >= mid) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        if (arr[lo] == lo) return lo;
        return -1;
    }
};