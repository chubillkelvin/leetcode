#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int n;
    int days;
    vector<int> jobs;
    vector<vector<int>> ans;

    int solve(int currDay, int currJob) {
        if (ans[currDay][currJob] != -1) return ans[currDay][currJob];
        int jobsLeft = n - currJob;
        int daysLeft = days - currDay;
        if (jobsLeft < daysLeft) {
            ans[currDay][currJob] = -1;
            return -1;
        }
        if (jobsLeft == daysLeft) {
            int difficulty = 0;
            for (int i = currJob; i < n; i++) difficulty += jobs[i];
            ans[currDay][currJob] = difficulty;
            return difficulty;
        }
        if (daysLeft == 1) {
            int difficulty = 0;
            for (int i = currJob; i < n; i++) {
                difficulty = max(difficulty, jobs[i]);
            }
            ans[currDay][currJob] = difficulty;
            return difficulty;
        } else {
            int currMaxJob = jobs[currJob];
            int difficulty = 9999999;
            for (int i = currJob; i < n - 1; i++) {
                int restDifficulties = solve(currDay + 1, i + 1);
                if (restDifficulties == -1) continue;
                currMaxJob = max(currMaxJob, jobs[i]);
                difficulty = min(difficulty, currMaxJob + restDifficulties);
            }
            ans[currDay][currJob] = difficulty == 9999999 ? -1 : difficulty;
            return ans[currDay][currJob];
        }
    }

    int minDifficulty(vector<int> &jobDifficulty, int d) {
        n = jobDifficulty.size();
        days = d;
        jobs = jobDifficulty;
        ans = vector<vector<int>>(d, vector<int>(n, -1));
        return solve(0, 0);
    }
};