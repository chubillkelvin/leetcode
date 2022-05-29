#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() <= 1) return false;
        if (s[0] != '$') return false;
        int dotCount = 0;
        for (int i = 1; i < s.size(); i++) {
            char c = s[i];
            if (c == '.') {
                dotCount++;
            } else {
                if (c - '0' < 0 || c - '0' > 9) return false;
            }
        }
        return dotCount <= 1;
    }

    string discountPrices(string sentence, int discount) {
        string temp;
        vector<string> words;
        for (char c: sentence) {
            if (c == ' ') {
                if (!temp.empty()) words.push_back(temp);
                temp = "";
            } else {
                temp += c;
            }
        }
        if (!temp.empty()) words.push_back(temp);
        for (int i = 0; i < words.size(); i++) {
            auto w = words[i];
            if (isValid(w)) {
                double num = stod(w.substr(1, w.size() - 1));
                if (num >= 0) {
                    num *= (100 - discount);
                    num = floor(num);
                    num /= 100;
                    temp = "$";
                    std::stringstream ss;
                    ss << std::fixed << std::setprecision(2) << num;
                    temp += ss.str();
                    words[i] = temp;
                }
            }
        }
        string ans;
        for (int i = 0; i < words.size(); i++) {
            ans += words[i];
            if (i < words.size() - 1) ans += ' ';
        }
        return ans;
    }
};