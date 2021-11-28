#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumBuckets(string street) {
        if (street == "H") return -1;
        if (street == ".") return 0;
        if (street == "..") return 0;
        if (street == ".H") return 1;
        if (street == "H.") return 1;
        if (street == "HH") return -1;

        int count = 0;
        for (int i = 0; i < street.size(); i++) {
            char prev, curr, next;
            if (i > 0) prev = street[i - 1];
            curr = street[i];
            if (i < street.size() - 1) next = street[i + 1];
            if (curr == 'H') {
                if (i == 0 && next == 'H') return -1;
                if (i == street.size() - 1 && prev == 'H') return -1;
                if (prev == '.' || next == '.') {
                    count++;
                    if (next == '.') {
                        i += 2;
                    }
                } else {
                    return -1;
                }
            }
        }
        return count;
    }
};