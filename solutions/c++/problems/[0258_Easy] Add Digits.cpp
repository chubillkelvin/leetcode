class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while (s.size() > 1) {
            int sum = 0;
            for (char c: s) sum += c - '0';
            s = to_string(sum);
        }
        return stoi(s);
    }
};