#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int wateringPlants(vector<int> &plants, int capacity) {
        int steps = 0;
        int currCapacity = capacity;
        for (int i = 0; i < plants.size(); i++) {
            int next = plants[i];
            if (currCapacity >= next) {
                steps++;
                currCapacity -= next;
            } else {
                steps += 2 * i + 1;
                currCapacity = capacity - next;
            }
        }
        return steps;
    }
};