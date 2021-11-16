#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char curr = s[i];
            if (isdigit(curr)) {
                i++;
                int repeat = (int) curr - 48;
                string strToRepeat = "";
                int openBracketToMatch = 0;
                for (int j = i; j < s.size(); i++, j++) {
                    char curr2 = s[j];
                    if (isdigit(curr2)) {
                        // curr2 == [0-9]
                        if (openBracketToMatch == 0) {
                            repeat *= 10;
                            repeat += (int) curr2 - 48;
                        } else {
                            strToRepeat += curr2;
                        }
                    } else if (curr2 == '[') {
                        // curr2 == '['
                        openBracketToMatch++;
                        if (openBracketToMatch != 1) {
                            strToRepeat += '[';
                        }
                    } else if (curr2 == ']') {
                        // curr2 == ']'
                        openBracketToMatch--;
                        if (openBracketToMatch == 0) {
                            strToRepeat = decodeString(strToRepeat);
                            break;
                        } else {
                            strToRepeat += ']';
                        }
                    } else {
                        // curr2 == [a-z]
                        strToRepeat += curr2;
                    }
                }
                for (int k = 0; k < repeat; k++) {
                    ans += strToRepeat;
                }
            } else {
                ans += curr;
            }
        }

        return ans;
    }
};