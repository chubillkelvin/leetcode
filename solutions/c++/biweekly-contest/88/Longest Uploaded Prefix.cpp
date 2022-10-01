#include <bits/stdc++.h>

using namespace std;

class BIT {
    int n;
    vector<int> bit;
public:
    BIT(int n) {
        n++;
        this->n = n;
        bit = vector<int>(n + 1, 0);
    }

    void add(int i, int num) {
        i++;
        while (i <= n) {
            bit[i] += num;
            i += i & -i;
        }
    }

    int sum(int i) {
        i++;
        int sum = 0;
        while (i > 0) {
            sum += bit[i];
            i -= i & -i;
        }
        return sum;
    }
};

class LUPrefix {
    int count = 0;
    int prefix = 0;
    BIT *bit;
public:
    LUPrefix(int n) {
        bit = new BIT(n);
    }

    void upload(int video) {
        count++;
        bit->add(video, 1);
    }

    int longest() {
        if (count == 0) return 0;
        int lo = 0;
        int hi = count;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2 + 1;
            if (bit->sum(mid) == mid) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        prefix = max(prefix, lo);
        return prefix;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */