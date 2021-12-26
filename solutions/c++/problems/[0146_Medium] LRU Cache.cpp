#include <bits/stdc++.h>

using namespace std;

class LRUCache {
    int capacity;
    list<int> cache;
    unordered_map<int, int> vMap;
    unordered_map<int, list<int>::iterator> iMap;

public:
    void updateCache(int key) {
        if (vMap.count(key) > 0) cache.erase(iMap[key]);
        cache.push_front(key);
        iMap[key] = cache.begin();
    }

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (vMap.count(key) > 0) {
            updateCache(key);
            return vMap[key];
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        updateCache(key);
        vMap[key] = value;
        while (cache.size() > capacity) {
            auto last = cache.back();
            vMap.erase(last);
            iMap.erase(last);
            cache.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */