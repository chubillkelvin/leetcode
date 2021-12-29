class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2 != 0) return false;
        stack<char> open;
        int free = 0;
        for(int i = 0; i < n; i++) {
            bool isLocked = locked[i] == '1';
            if (!isLocked) {
                free++;
                continue;
            }
            char c = s[i];
            if (c == '(') {
                open.push('(');
            } else {
                if (open.size() > 0) {
                    open.pop();
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }

        stack<char> openR;
        free = 0;
        for(int i = n - 1; i >= 0; i--) {
            bool isLocked = locked[i] == '1';
            if (!isLocked) {
                free++;
                continue;
            }
            char c = s[i];
            if (c == ')') {
                openR.push(')');
            } else {
                if (openR.size() > 0) {
                    openR.pop();
                } else if (free > 0) {
                    free--;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};