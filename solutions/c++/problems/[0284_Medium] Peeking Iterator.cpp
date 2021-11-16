#include <bits/stdc++.h>

using namespace std;


class PeekingIterator : public Iterator {
private:
    bool hasPeeked = false;
    int peekedNum;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums) {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        if (!hasPeeked) {
            hasPeeked = true;
            peekedNum = Iterator::next();
        }
        return peekedNum;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        if (hasPeeked) {
            hasPeeked = false;
            return peekedNum;
        } else {
            return Iterator::next();
        }
    }

    bool hasNext() const {
        return hasPeeked || Iterator::hasNext();
    }
};
