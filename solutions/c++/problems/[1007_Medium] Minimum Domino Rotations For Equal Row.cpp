class Solution {
public:
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        int n = tops.size();
        vector<int> uniqueCount(6, 0);
        vector<int> topCount(6, 0);
        vector<int> bottomCount(6, 0);
        for (int i = 0; i < n; i++) {
            topCount[tops[i] - 1]++;
            bottomCount[bottoms[i] - 1]++;
            if (tops[i] == bottoms[i]) {
                uniqueCount[tops[i] - 1]++;
            } else {
                uniqueCount[tops[i] - 1]++;
                uniqueCount[bottoms[i] - 1]++;
            }
        }
        vector<int> candidates;
        for (int i = 0; i < 6; i++) {
            if (uniqueCount[i] == n) candidates.push_back(i);
        }
        if (candidates.empty()) return -1;
        int ans = n;
        for (int candidate: candidates) {
            ans = min(ans, min(n - topCount[candidate], n - bottomCount[candidate]));
        }
        return ans;
    }
};