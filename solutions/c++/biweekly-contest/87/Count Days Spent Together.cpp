#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int getDay(string s) {
        int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        string m, d;
        m += s[0];
        m += s[1];
        d += s[3];
        d += s[4];
        int days = stoi(d);
        int month = stoi(m);
        for (int i = 0; i < month - 1; i++) days += months[i];
        return days;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        auto aliceA = getDay(arriveAlice);
        auto aliceL = getDay(leaveAlice);
        auto bobA = getDay(arriveBob);
        auto bobL = getDay(leaveBob);
        if (aliceL <= bobL) {
            if (aliceL >= bobA) return min(aliceL, bobL) - max(aliceA, bobA) + 1;
        } else {
            if (bobL >= aliceA) return min(aliceL, bobL) - max(aliceA, bobA) + 1;
        }
        return 0;
    }
};