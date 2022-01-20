class ZigzagIterator {
    vector<int> v1, v2;
    int i1 = 0;
    int i2 = 0;
    int n1, n2;
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        n1 = v1.size();
        n2 = v2.size();
        this->v1 = v1;
        this->v2 = v2;
    }

    int next() {
        if (i1 <= i2 && i1 < n1) {
            return v1[i1++];
        } else if (i2 < n2) {
            return v2[i2++];
        } else {
            return v1[i1++];
        }
    }

    bool hasNext() {
        return i1 < n1 || i2 < n2;
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */