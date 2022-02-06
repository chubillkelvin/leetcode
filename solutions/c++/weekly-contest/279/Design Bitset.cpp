#include <bits/stdc++.h>

using namespace std;

class Bitset {
    int size, oneCount;
    bool flipped = false;
    string bSet = "";
    string fSet = "";
public:
    Bitset(int size) {
        this->size = size;
        oneCount = 0;
        bSet.reserve(size);
        for (int i = 0; i < size; i++) {
            bSet += '0';
            fSet += '1';
        }
    }

    void fix(int idx) {
        if (flipped) {
            if (fSet[idx] != '1') {
                oneCount++;
                fSet[idx] = '1';
                bSet[idx] = '0';
            }
        } else {
            if (bSet[idx] != '1') {
                oneCount++;
                bSet[idx] = '1';
                fSet[idx] = '0';
            }
        }
    }

    void unfix(int idx) {
        if (flipped) {
            if (fSet[idx] != '0') {
                oneCount--;
                fSet[idx] = '0';
                bSet[idx] = '1';
            }
        } else {
            if (bSet[idx] != '0') {
                oneCount--;
                bSet[idx] = '0';
                fSet[idx] = '1';
            }
        }
    }

    void flip() {
        flipped = !flipped;
        oneCount = size - oneCount;
    }

    bool all() {
        return oneCount == size;
    }

    bool one() {
        return oneCount > 0;
    }

    int count() {
        return oneCount;
    }

    string toString() {
        return flipped ? fSet : bSet;
    }
};

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */