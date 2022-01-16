class Solution {
public:
    int maxDistToClosest(vector<int> &seats) {
        int n = seats.size();
        int maxEmpty = 0;
        int firstCurr = -1;
        int curr = 0;
        for (int i = 0; i < n; i++) {
            if (seats[i] == 0) {
                curr++;
            } else {
                maxEmpty = max(maxEmpty, curr);
                if (firstCurr == -1) firstCurr = curr;
                curr = 0;
            }
        }
        if (maxEmpty % 2 == 0) {
            return max(maxEmpty / 2, max(firstCurr, curr));
        } else {
            return max(maxEmpty / 2 + 1, max(firstCurr, curr));
        }
    }
};