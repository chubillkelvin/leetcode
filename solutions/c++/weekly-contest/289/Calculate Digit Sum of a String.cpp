#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string digitSum(string s, int k) {
        string temp = s;
        while (temp.size() > k) {
            string temp2;
            for (int i = 0; i < temp.size(); i += k) {
                int num = 0;
                for (int j = 0; j < k; j++) {
                    if (i + j >= temp.size()) break;
                    num += temp[i + j] - '0';
                }
                temp2 += to_string(num);
            }
            temp = temp2;
        }
        return temp;
    }
};