#include <bits/stdc++.h>

using namespace std;

class SmallestInfiniteSet {
    set<int> s;
public:
    SmallestInfiniteSet() {
        for (int i = 1; i <= 1000; i++) s.insert(i);
    }

    int popSmallest() {
        int num = *s.begin();
        s.erase(num);
        return num;
    }

    void addBack(int num) {
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */