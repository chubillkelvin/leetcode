#include <bits/stdc++.h>

using namespace std;

class Solution {
    unordered_map<char, int> end;
public:
    int k, power, modulo;

    int hash(char c, int index) {
        long long num = c - 'a' + 1;
        while (index-- > 0) num = (num * power) % modulo;
        return num;
    }

    int endHash(char c) {
        if (end[c]) return end[c];
        return end[c] = hash(c, k - 1);
    }

    int getHash(string s) {
        int n = s.size();
        long long hashed = 0;
        for (int i = 0; i < n; i++) {
            char c = s[i];
            hashed = (hashed + hash(c, i)) % modulo;
        }
        return hashed;
    }

    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        this->k = k;
        this->power = power;
        this->modulo = modulo;
        int n = s.size();
        unordered_map<int, int> index;
        long long hashed = getHash(s.substr(n - k, k));
        index[hashed] = n - k;
        for (int i = n - k - 1; i >= 0; i--) {
            char prev = s[i + k];
            char curr = s[i];
            hashed = ((hashed - endHash(prev) + modulo) * power + curr - 'a' + 1) % modulo;
            index[hashed] = i;
        }
        return s.substr(index[hashValue], k);
    }
};