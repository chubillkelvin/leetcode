#include <bits/stdc++.h>

using namespace std;

class NumberContainers {
    unordered_map<int, int> pos;
    unordered_map<int, set<int>> s;
public:
    NumberContainers() {

    }

    void change(int index, int number) {
        if (pos.count(index)) {
            s[pos[index]].erase(index);
            pos.erase(index);
        }
        pos[index] = number;
        s[number].insert(index);
    }

    int find(int number) {
        if (s.count(number) && s[number].size() > 0) {
            return *s[number].begin();
        } else {
            return -1;
        }
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */