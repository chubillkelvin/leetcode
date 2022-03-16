class Solution {
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        int n = pushed.size();
        stack<int> s;
        int i = 0;
        int j = 0;
        while (i < n || j < n) {
            if (s.empty() || s.top() != popped[j]) {
                if (i >= n) return false;
                s.push(pushed[i]);
                i++;
            } else {
                s.pop();
                j++;
            }
        }
        return true;
    }
};