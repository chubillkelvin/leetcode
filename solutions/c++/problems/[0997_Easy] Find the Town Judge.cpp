class Solution {
public:
    int findJudge(int n, vector <vector<int>> &trust) {
        vector<int> trusting(n, 0);
        vector<int> trusted(n, 0);
        for (auto t: trust) {
            trusting[t[0] - 1]++;
            trusted[t[1] - 1]++;
        }
        for (int i = 0; i < n; i++) {
            if (trusting[i] == 0 && trusted[i] == n - 1) return i + 1;
        }
        return -1;
    }
};