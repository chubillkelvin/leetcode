#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minimumRefill(vector<int> &plants, int capacityA, int capacityB) {
        int n = plants.size();
        int currA = capacityA;
        int currB = capacityB;
        int posA = 0;
        int posB = n - 1;
        int count = 0;
        while (posA <= posB) {
            if (posA == posB) {
                int plant = plants[posA];
                int maxCurr = max(currA, currB);
                if (plant > maxCurr) {
                    count++;
                }
                break;
            } else {
                // water A
                int plantA = plants[posA];
                if (plantA > currA) {
                    count++;
                    currA = capacityA;
                }
                currA -= plantA;
                posA++;

                // water B
                int plantB = plants[posB];
                if (plantB > currB) {
                    count++;
                    currB = capacityB;
                }
                currB -= plantB;
                posB--;
            }
        }
        return count;
    }
};