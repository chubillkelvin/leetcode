#include <bits/stdc++.h>

using namespace std;

class ATM {
    vector<int> val = {20, 50, 100, 200, 500};
    vector<long long> notes;
public:
    ATM() {
        notes = vector<long long>(5, 0);
    }

    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) {
            notes[i] += banknotesCount[i];
        }
    }

    vector<int> withdraw(int amount) {
        vector<int> res(5, 0);
        int startIndex = 4;
        if (amount < 500) startIndex = 3;
        if (amount < 200) startIndex = 2;
        if (amount < 100) startIndex = 1;
        if (amount < 50) startIndex = 0;
        int temp = 0;
        for (int i = startIndex; i >= 0; i--) {
            if (amount - temp < val[i]) continue;
            long long curr = (amount - temp) / val[i];
            curr = min(curr, notes[i]);
            res[i] = curr;
            temp += curr * val[i];
        }
        if (temp != amount) return {-1};
        for (int i = 0; i < 5; i++) {
            notes[i] -= res[i];
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */