class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        string sign = "";
        string nums = "";
        int i = 0;
        while (i < n) {
            char curr = s[i];
            i++;
            if (curr == ' ') {
                if (nums.empty() && i - 1 == 0 || s[i - 2] == ' ') continue;
                break;
            } else if (curr == '+' || curr == '-') {
                if (nums.empty() && sign.empty() && i - 1 == 0 || s[i - 2] == ' ') {
                    sign += curr;
                    continue;
                }
                break;
            } else if (curr - '0' >= 0 && curr - '0' <= 9) {
                if (curr == '0' && nums.empty()) continue;
                nums += curr;
            } else {
                break;
            }
        }
        long exp = 1;
        long result = 0;
        bool isNegative = sign == "-";
        bool isOverflow = false;
        while (!nums.empty()) {
            result += (nums.back() - '0') * exp;
            nums.pop_back();
            if (isNegative) {
                if (-result < INT_MIN) {
                    isOverflow = true;
                    break;
                }
            } else {
                if (result > INT_MAX) {
                    isOverflow = true;
                    break;
                }
            }
            if (exp > INT_MAX) {
                isOverflow = true;
                break;
            }
            exp *= 10;
        }
        if (isOverflow) {
            return isNegative ? INT_MIN : INT_MAX;
        }
        return isNegative ? -result : result;
    }
};