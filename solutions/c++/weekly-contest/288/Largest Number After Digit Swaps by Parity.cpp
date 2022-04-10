#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int largestInteger(int num) {
        string number = to_string(num);
        vector<char> evens;
        vector<int> evenIdx;
        vector<char> odds;
        vector<int> oddIdx;
        for (int i = 0; i < number.size(); i++) {
            char c = number[i];
            if ((c - '0') % 2 == 0) {
                evens.push_back(c);
                evenIdx.push_back(i);
            } else {
                odds.push_back(c);
                oddIdx.push_back(i);
            }
        }
        sort(evens.begin(), evens.end(), greater<>());
        sort(odds.begin(), odds.end(), greater<>());
        for (int i = 0; i < evens.size(); i++) {
            number[evenIdx[i]] = evens[i];
        }
        for (int i = 0; i < odds.size(); i++) {
            number[oddIdx[i]] = odds[i];
        }
        return stoi(number);
    }
};