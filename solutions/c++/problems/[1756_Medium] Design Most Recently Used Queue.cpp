class MRUQueue {
    list<int> q;
public:
    MRUQueue(int n) {
        for (int i = 1; i <= n; i++) {
            q.push_back(i);
        }
    }

    int fetch(int k) {
        auto target = q.begin();
        advance(target, k - 1);
        int item = *target;
        q.erase(target);
        q.push_back(item);
        return item;
    }
};

/**
 * Your MRUQueue object will be instantiated and called as such:
 * MRUQueue* obj = new MRUQueue(n);
 * int param_1 = obj->fetch(k);
 */