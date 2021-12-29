class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n-1);
        string ans = "";
        char currChar = prev[0];
        int count = 1;
        for(int i = 1; i < prev.size(); i++) {
            char c = prev[i];
            if (c == currChar) {
                count++;
            } else {
                ans += to_string(count) + currChar;
                currChar = c;
                count = 1;
            }
        }
        ans += to_string(count) + currChar;
        return ans;
    }
};