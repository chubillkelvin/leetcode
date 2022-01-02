class Solution {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        int n = time.size();
        multiset<int> timeSet;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int curr = time[i];
            count += timeSet.count((60 - curr % 60) % 60);
            timeSet.insert(curr % 60);
        }
        return count;
    }
};