#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int lo = 0;
        int hi = n - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (arr[mid] >= x) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        lo -= 1;
        hi = lo + 1;
        while (hi - lo - 1 < k) {
            if (lo < 0) {
                hi++;
            } else if (hi >= n) {
                lo--;
            } else if (abs(arr[lo] - x) <= abs(arr[hi] - x)) {
                lo--;
            } else {
                hi++;
            }
        }
        vector<int> ans;
        for (int i = lo + 1; i < hi; i++) ans.push_back(arr[i]);
        return ans;
    }
};