class Solution {
public:
    int getTotalTime(vector<int> &piles, int speed) {
        int n = piles.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += piles[i] / speed;
            if (piles[i] % speed != 0) total++;
        }
        return total;
    }

    int minEatingSpeed(vector<int> &piles, int h) {
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int hi = piles.back();
        int lo = 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            int total = getTotalTime(piles, mid);
            if (total <= h) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};