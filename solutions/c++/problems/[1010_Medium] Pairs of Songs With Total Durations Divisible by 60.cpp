class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int n = time.size();
        vector<int> timeSet(60);
        int count = 0;
        for (int i = 0; i < n; i++) {
            int curr = time[i];
            count += timeSet[(60 - curr % 60) % 60];
            timeSet[curr % 60]++;
        }
        return count;
    }
};