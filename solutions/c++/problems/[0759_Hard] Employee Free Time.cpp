/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector <Interval> employeeFreeTime(vector <vector<Interval>> schedule) {
        vector <vector<int>> time;
        for (auto employee: schedule) {
            for (auto work: employee) {
                time.push_back({work.start, work.end});
            }
        }
        sort(time.begin(), time.end(), [](auto &t1, auto &t2) {
            return t1[1] < t2[1];
        });
        cout << "schedule: ";
        for (auto t: time) cout << "[" << t[0] << "," << t[1] << "], ";
        cout << endl;
        int n = time.size();
        vector <Interval> ans;
        for (int i = 0; i < n - 1; i++) {
            auto curr = time[i];
            auto next = time[i + 1];
            cout << "curr[1]: " << curr[1] << ", next[0]: " << next[0] << endl;
            if (curr[1] < next[0]) ans.push_back(Interval(curr[1], next[0]));
        }
        return {};
    }
};