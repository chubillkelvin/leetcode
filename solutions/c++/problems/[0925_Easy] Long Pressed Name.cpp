class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int n = name.size();
        int m = typed.size();
        int i2 = 0;
        for (int i = 0; i < n; i++) {
            int count = 1;
            char c = name[i];
            while (i < n - 1 && c == name[i+1]) {
                i++;
                count++;
            }
            while (i2 < m && typed[i2] == c) {
                i2++;
                count--;
            }
            if (count > 0) return false;
        }
        return i2 == m;
    }
};