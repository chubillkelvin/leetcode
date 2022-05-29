#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        unordered_map<char, int> count;
        for (char c: s) count[c]++;
        unordered_map<char, int> required;
        for (char c: target) required[c]++;
        int minCount = INT_MAX;
        for (auto p: required) {
            minCount = min(minCount, count[p.first] / p.second);
        }
        return minCount;
    }
};