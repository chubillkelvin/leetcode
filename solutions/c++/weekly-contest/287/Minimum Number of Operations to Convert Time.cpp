#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int convertTime(string current, string correct) {
        int currTime = 0;
        currTime += (current[0] - '0') * 10 * 60;
        currTime += (current[1] - '0') * 60;
        currTime += (current[3] - '0') * 10;
        currTime += (current[4] - '0');
        int correctTime = 0;
        correctTime += (correct[0] - '0') * 10 * 60;
        correctTime += (correct[1] - '0') * 60;
        correctTime += (correct[3] - '0') * 10;
        correctTime += (correct[4] - '0');
        if (correctTime < currTime) correctTime += 24 * 60;
        int count = 0;
        while (correctTime - currTime >= 60) {
            currTime += 60;
            count++;
        }
        while (correctTime - currTime >= 15) {
            currTime += 15;
            count++;
        }
        while (correctTime - currTime >= 5) {
            currTime += 5;
            count++;
        }
        while (correctTime - currTime >= 1) {
            currTime += 1;
            count++;
        }
        return count;
    }
};