#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBits = bitset<32>(num2).count();
        if (setBits == 0) return 0;
        auto b = bitset<32>(num1).to_string();
        string ans;
        for (int i = 0; i < 32; i++) ans += '0';
        for (int i = 0; i < 32; i++) {
            if (b[i] == '0') continue;
            ans[i] = '1';
            setBits--;
            if (setBits == 0) break;
        }
        int i = 32;
        while (setBits > 0 && i >= 0) {
            if (ans[i] == '0') {
                ans[i] = '1';
                setBits--;
            }
            i--;
        }
        return bitset<32>(ans).to_ullong();
    }
};