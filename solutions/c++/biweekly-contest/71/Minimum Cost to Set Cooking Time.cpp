#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
        vector<string> com;
        string com1 = "";
        string ten = to_string(min(99, targetSeconds / 60));
        com1 += ten.size() == 1 ? "0" + ten : ten;
        string one = to_string(targetSeconds / 60 > 99 ? targetSeconds % 60 + 60 : targetSeconds % 60);
        com1 += one.size() == 1 ? "0" + one : one;
        com.push_back(com1);
        if (targetSeconds >= 60 && targetSeconds < 5980) {
            string com2 = "";
            ten = to_string(targetSeconds / 60 - 1);
            com2 += ten.size() == 1 ? "0" + ten : ten;
            one = to_string(targetSeconds % 60 + 60);
            com2 += one.size() == 1 ? "0" + one : one;
            if (com2.size() <= 4) com.push_back(com2);
        }
        int minCost = INT_MAX;
        for (int i = 0; i < com.size(); i++) {
            string curr = com[i];
            int cost = 0;
            char currNum = to_string(startAt)[0];
            for (int j = 0; j < 4; j++) {
                char c = curr[j];
                if (cost == 0 && c == '0') continue;
                if (c == currNum) {
                    cost += pushCost;
                } else {
                    currNum = c;
                    cost += moveCost + pushCost;
                }
            }
            minCost = min(minCost, cost);
        }
        return minCost;
    }
};