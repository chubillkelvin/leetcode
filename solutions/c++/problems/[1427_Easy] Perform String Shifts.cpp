class Solution {
public:
    string stringShift(string s, vector <vector<int>> &shift) {
        int n = s.size();
        int totalShift = 0;
        for (auto p: shift) {
            if (p[0] == 0) {
                totalShift = (totalShift + p[1] + n) % n;
            } else {
                totalShift = (totalShift - p[1] + n) % n;
            }
        }
        string ans = "";
        for (int i = 0; i < n; i++) {
            ans += s[(i + totalShift + n) % n];
        }
        return ans;
    }
};