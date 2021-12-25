#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void handleTemp(string &temp, vector<int> &nums, vector<char> &operators) {
        if (!temp.empty()) {
            int curr = stoi(temp);
            temp = "";
            if (!operators.empty() && !nums.empty()) {
                char opt = operators.back();
                if (opt == '*' || opt == '/') {
                    int prev = nums.back();
                    nums.pop_back();
                    operators.pop_back();
                    nums.push_back(getResult(prev, curr, opt));
                    return;
                }
            }
            nums.push_back(curr);
        }
    }

    int getResult(int num1, int num2, char opt) {
        switch (opt) {
            case '+':
                return num1 + num2;
            case '-':
                return num1 - num2;
            case '*':
                return num1 * num2;
            case '/':
                return num1 / num2;
        }
        return 0;
    }

    int calculate(string s) {
        vector<int> nums;
        vector<char> operators;
        string temp;
        for (auto c: s) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                temp += c;
                continue;
            }
            handleTemp(temp, nums, operators);
            if (c != ' ') {
                operators.push_back(c);
            }
        }
        handleTemp(temp, nums, operators);
        int res = nums[0];
        for (int i = 0; i < operators.size(); i++) {
            res = getResult(res, nums[i + 1], operators[i]);
        }
        return res;
    }
};