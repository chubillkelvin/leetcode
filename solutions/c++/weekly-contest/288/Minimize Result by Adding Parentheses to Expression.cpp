#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string minimizeResult(string expression) {
        string left, right;
        bool foundPlus = false;
        for (char c: expression) {
            if (c == '+') {
                foundPlus = true;
            } else if (foundPlus) {
                right += c;
            } else {
                left += c;
            }
        }
        int currMin = INT_MAX;
        string ans;
        int leftIdx = left.size() - 1;
        int rightIdx = 0;
        while (leftIdx >= 0 && rightIdx < right.size()) {
            string leftString = left.substr(0, leftIdx);
            int l = leftString.size() > 0 ? stoi(leftString) : 1;
            string leftSumString = left.substr(leftIdx, left.size() - leftIdx);
            string rightSumString = right.substr(0, rightIdx + 1);
            int sum = stoi(leftSumString) + stoi(rightSumString);
            string rightString = right.substr(rightIdx + 1, right.size() - rightIdx - 1);
            int r = rightString.size() > 0 ? stoi(rightString) : 1;
            int temp = l * sum * r;
            if (temp < currMin) {
                currMin = temp;
                ans = leftString + '(' + leftSumString + '+' + rightSumString + ')' + rightString;
            }
            if (leftIdx - 1 >= 0 && rightIdx + 1 < right.size()) {
                int tempLeft = left.size() - 1 - leftIdx;
                if (leftString == "1") {
                    rightIdx++;
                } else if (rightString == "1") {
                    leftIdx--;
                } else if (tempLeft > rightIdx) {
                    rightIdx++;
                } else if (rightIdx > tempLeft) {
                    leftIdx--;
                } else if (left[leftIdx - 1] >= right[rightIdx + 1]) {
                    leftIdx--;
                } else {
                    rightIdx++;
                }
            } else if (leftIdx - 1 >= 0) {
                leftIdx--;
            } else if (rightIdx + 1 < right.size()) {
                rightIdx++;
            } else {
                break;
            }
        }
        return ans;
    }
};